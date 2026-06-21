# NVIDIA Cosmos Transfer 2.5 Setup

This project uses NVIDIA Cosmos Transfer 2.5 to convert the synthetic crane defect
dataset in `dataset/synthetic_v2/` into more photorealistic augmented samples in
`dataset/augmented/`.

Official references:

- Cosmos Cookbook: https://nvidia-cosmos.github.io/cosmos-cookbook/
- Hugging Face model family: https://huggingface.co/nvidia/Cosmos-Transfer2.5
- General 2B checkpoints used by the repo docs: https://huggingface.co/nvidia/Cosmos-Transfer2.5-2B
- Local cloned docs: `/tmp/cosmos-transfer2.5/README.md` and `/tmp/cosmos-transfer2.5/docs/inference.md`

Note: the upstream README says Cosmos Transfer 2.5 is now in limited maintenance
after the June 1, 2026 Cosmos 3 release. These steps still document Transfer 2.5
because that is the requested augmentation path.

## System Requirements

From the official `docs/setup.md` and `docs/inference.md`:

- Linux x86-64.
- glibc 2.35 or newer, for example Ubuntu 22.04 or newer.
- NVIDIA GPU with Ampere architecture or newer, such as RTX 30 Series, A100,
  H100, H200, B200, or newer.
- NVIDIA driver `>=570.124.06` for CUDA 12.8.1 compatibility.
- CUDA variant selected through the install extra:
  - CUDA 12.8: `uv sync --extra=cu128`
  - CUDA 13.0: `uv sync --extra=cu130`
- Python `>=3.10`.
- PyTorch is installed through `cosmos-oss` extras:
  - `cosmos-oss[cu128_torch27]` for CUDA 12.8.
  - `cosmos-oss[cu130_torch29]` for CUDA 13.0.
- Cosmos-Transfer2.5-2B single-GPU inference requires about 65.4 GB of GPU
  VRAM. Use multi-GPU `torchrun` when available.

## Installation

The repository uses `pyproject.toml` and `uv`; it does not provide a
`requirements.txt`.

```bash
sudo apt update
sudo apt -y install curl ffmpeg git-lfs libx11-dev tree wget
git lfs install

git clone https://github.com/nvidia-cosmos/cosmos-transfer2.5 /tmp/cosmos-transfer2.5
cd /tmp/cosmos-transfer2.5
git lfs pull
```

Install `uv` and create the CUDA 12.8 environment:

```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
source "$HOME/.local/bin/env"

uv python install
uv sync --extra=cu128
source .venv/bin/activate
```

For CUDA 13.0, including DGX Spark and Jetson AGX targets, use:

```bash
uv sync --extra=cu130
source .venv/bin/activate
```

To install into an already active environment instead:

```bash
uv sync --extra=cu128 --active --inexact
```

## Model Download

Checkpoints are downloaded from Hugging Face during inference. To prepare access:

```bash
uv tool install -U "huggingface_hub[cli]"
hf auth login
```

Then accept the NVIDIA model license on Hugging Face before running inference.
The official setup guide also calls out the Cosmos Guardrail license gate.

To control cache location:

```bash
export HF_HOME=/path/to/hf_cache
```

## Input Data Format

The general Transfer 2.5 inference entry point consumes a JSON spec plus video
assets. The important fields are:

- `prompt` or `prompt_path`: text prompt describing the target photorealistic
  scene.
- `video_path`: input RGB video, usually an `.mp4`.
- Optional control modalities under keys such as `depth`, `edge`, `seg`, and
  `vis`.
- Each control can include `control_path`, `mask_path`, and `control_weight`.
- If a supported control input is omitted, Cosmos can compute some controls on
  the fly from the input video.

This project currently has 100 still PNG frames and YOLO labels:

```text
dataset/synthetic_v2/images/frame_000001.png
dataset/synthetic_v2/labels_yolo/frame_000001.txt
dataset/synthetic_v2/metadata.json
```

For Transfer 2.5 video inference, prepare those still frames as one or more
short RGB videos before calling Cosmos. A practical first pass is to pack the
100 images into one 16 FPS MP4, or into shorter chunks if you want separate
prompts/control settings:

```bash
ffmpeg -framerate 16 \
  -i dataset/synthetic_v2/images/frame_%06d.png \
  -pix_fmt yuv420p \
  dataset/augmented/cosmos_inputs/crane_synthetic_rgb.mp4
```

Keep labels and metadata beside the generated variants so downstream training
can trace each augmented frame back to its source frame.

## Example Inference Command

From the official inference docs, a single-GPU example is:

```bash
cd /tmp/cosmos-transfer2.5
python examples/inference.py \
  -i assets/robot_example/edge/robot_edge_spec.json \
  -o outputs/edge
```

For multi-GPU inference:

```bash
cd /tmp/cosmos-transfer2.5
torchrun --nproc_per_node=8 --master_port=12341 examples/inference.py \
  -i assets/robot_example/edge/robot_edge_spec.json \
  -o outputs/edge
```

For the Pegasus crane dataset, generate a project-specific spec with:

```bash
python scripts/cosmos_augment_pipeline.py \
  --input-dir dataset/synthetic_v2 \
  --output-dir dataset/augmented \
  --cosmos-repo /tmp/cosmos-transfer2.5 \
  --prepare-only
```

Then review the generated spec under `dataset/augmented/cosmos_inputs/` and run
Cosmos from its repository, for example:

```bash
cd /tmp/cosmos-transfer2.5
python examples/inference.py \
  -i /workspaces/pegasus_ws/dataset/augmented/cosmos_inputs/crane_transfer_spec.json \
  -o /workspaces/pegasus_ws/dataset/augmented/cosmos_outputs
```

The generated stub does not run GPU inference by default. Pass `--run-cosmos`
only after the Cosmos environment, model access, and input videos are ready.
