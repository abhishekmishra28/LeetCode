import os
import re

BASE = "./"
categories = {
    "Arrays": "Arrays",
    "Strings": "Strings",
    "Linked List": "Linked List",
    "Trees": "Trees",
    "Graphs": "Graphs",
    "Dynamic Programming": "DynamicProgramming",
    "Greedy Algorithm" : "GreedyAlgorithm",
    "Math": "Math",
    "Design": "Design",
    "Others": "Others"
}

counts = {}

for label, folder in categories.items():
    path = os.path.join(BASE, folder)
    if os.path.exists(path):
        counts[label] = len(
            [f for f in os.listdir(path) if f.endswith(".cpp")]
        )
    else:
        counts[label] = 0

total = sum(counts.values())   # ➜ NEW

with open("README.md", "r") as f:
    content = f.read()

table = (
    "| Category | Solved |\n"
    "|----------|--------|\n" +
    "\n".join([f"| {k} | {v} |" for k, v in counts.items()]) +
    f"\n| **Total** | **{total}** |"   # ➜ NEW
)

content = re.sub(
    r"\| Category \| Solved \|[\s\S]*?\| Others \s*\|\s*\d*\s*\|",
    table,
    content
)

with open("README.md", "w") as f:
    f.write(content)

print("Progress tracker updated 🎯")
