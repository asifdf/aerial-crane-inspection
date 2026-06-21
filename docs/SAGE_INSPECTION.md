# SAGE Inspection Report
## Scalable Agentic 3D Scene Generation

### What it is
SAGE generates simulation-ready 3D scenes from natural language task descriptions using an agentic framework. Given a prompt like *"fly a drone to inspect a crane for corrosion cracks"*, it produces a complete USD scene with objects, materials, physics, and layout — ready for Isaac Sim.

### Architecture

```
User Task → VLM Agent (Qwen3-VL-30B) → MCP Tool Selection
    ├── TRELLIS (3D asset generation)
    ├── MatFuse (material synthesis)
    ├── Layout Solver (physics-valid placement)
    └── Scene Packer → USD export
```

### Hardware Requirements

| Component | VRAM | Our RTX 4060 Ti (16GB) |
|-----------|------|----------------------|
| Qwen3-VL-30B (VLM agent) | ~60GB | ❌ — Use **Claude API** instead |
| TRELLIS.2 (3D assets) | 16-24GB | ✅ Tight but possible |
| MatFuse (materials) | ~8GB | ✅ |
| Isaac Sim (viewer) | ~5GB | ✅ Already running |

### Can we run it?

**Full pipeline**: ❌ — Qwen3-VL needs 60GB+. This runs on DGX/A100 clusters.

**What works locally**:
- ✅ **TRELLIS.2** (`pip install trellis`) can generate individual 3D crane part assets
- ✅ **SAGE-10k dataset** (10,000 pre-built scenes on HuggingFace) can be downloaded and loaded into Isaac Sim 5.1
- ✅ **Claude can replace the VLM agent** — the modular MCP architecture makes this straightforward

### Practical path forward

| Step | What | How |
|------|------|-----|
| 1 | Download SAGE-10k scenes | `huggingface.co/datasets/nvidia/SAGE-10k` |
| 2 | Browse for industrial/warehouse/crane scenes | Search SAGE-10k or Holodeck base data |
| 3 | If no crane found, use TRELLIS.2 to generate crane USD | `pip install trellis && python -c "..."` |
| 4 | Load in Isaac Sim | Drag USD into existing Pegasus environment |
| 5 | For full agentic flow | Replace Qwen3-VL with Claude API (same MCP interface) + run TRELLIS server on cloud |

### Alternatives to SAGE (already available)

We already have everything needed for the crane inspection demo:
- **Simple_Warehouse** environment (included in Isaac Sim 5.1)
- **Pegasus drone** (Iris quadrotor with downward camera)
- **Replicator** for synthetic defect data
- **Cosmos Transfer** for photorealistic augmentation

SAGE would be most useful for generating **novel crane inspection environments** at scale — e.g., 100 different crane types in different weather/lighting conditions. That's Phase 2+ territory.

### Status
| Check | Detail |
|-------|--------|
| ❌ | Full SAGE pipeline (needs 60GB+ GPU cluster) |
| ✅ | SAGE-10k dataset accessible on HuggingFace |
| ✅ | TRELLIS.2 installable (16GB VRAM minimum — tight on RTX 4060 Ti) |
| ✅ | Claude API as VLM replacement (drop-in via MCP) |
| ⏸️ | Not needed now — current Simple_Warehouse + Replicator pipeline suffices |
