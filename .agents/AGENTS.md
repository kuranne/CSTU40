# CSTU40 Knowledge Base - Agent Operations Manual

## 1. Overview & Scope
Central academic knowledge base and coursework repository for Computer Science, Thammasat University (Cohort 40).
This repository stores lecture notes, laboratory exercises, assignments, and curriculum indexes structured strictly around the CSTU curriculum.

Agents operating within this repository assist with note creation, structural organization, and academic indexing while adhering to the CSTU40 hierarchy.

---

## 2. CSTU40 Modular Rules Architecture

```
.agents/
├── rules/
│   ├── 01-tree-hierarchy.md      # Strict 5-tier tree model, parent-child traversal, no random cross-links
│   ├── 02-frontmatter-schema.md  # Tiered YAML schemas (class, parent, type), zero wikilinks
│   └── 03-workspace-structure.md # Course archetype layout, rosters, code parsing, copyright protection
└── AGENTS.md                     # CSTU40 operations manual
```

---

## 3. Structural Directives

### 3.1 Tree Hierarchy & Navigation
- Strict 5-tier tree: Root (`README.md`) -> Year -> Semester -> Course Hub -> Leaf Note.
- Downward navigation in note body (tables of contents, Dataview lists).
- Upward navigation declared in YAML frontmatter (`parent: "Parent Note"`).
- Sibling/leaf notes must NOT cross-link horizontally unless explicitly citing or depending on specific content from another file.
- Deprecate and prohibit legacy body breadcrumb callouts (`> [!info] Navigation:`).
- See detailed rules in [01-tree-hierarchy.md](file:///Users/kuranne/Library/Mobile%20Documents/iCloud~md~obsidian/Documents/Notebook/University/CSTU40/.agents/rules/01-tree-hierarchy.md).

### 3.2 YAML Frontmatter Schemas
- Every note requires valid YAML frontmatter.
- Mandatory fields for leaf notes: `class` (e.g. `CS261`), `type` (e.g. `lecture`, `lab`), `title`, `parent` (e.g. `"CS261"`).
- Plain YAML strings only; zero `[[wikilinks]]` in frontmatter.
- See full schemas in [02-frontmatter-schema.md](file:///Users/kuranne/Library/Mobile%20Documents/iCloud~md~obsidian/Documents/Notebook/University/CSTU40/.agents/rules/02-frontmatter-schema.md).

### 3.3 Workspace Archetype & Assets
- Course directory layout: `Year {N}/Semester {N}/{Course Code} - {Course Name}/[Assignments, Labs, Lectures, Assets, Private]`.
- Lecture code parsing: Ignore non-code lecture files; parse only source code (`.c`, `.cpp`, `.java`, `.py`, `.ipynb`, `.arm`, `.s`, `.h`).
- Copyright protection: Place official slides and syllabi in `<Course>/Private/Docs/` (`**/[Pp]rivate/**` gitignored).
- Zero file duplication; use symlinks or hard links (`ln -s` / `ln`).
- See detailed layout in [03-workspace-structure.md](file:///Users/kuranne/Library/Mobile%20Documents/iCloud~md~obsidian/Documents/Notebook/University/CSTU40/.agents/rules/03-workspace-structure.md).

---

## 4. Inherited Vault Standards
This repository resides inside the parent Obsidian vault (`Notebook`). Agents must comply with parent vault standards:
- **Style & Language**: Zero-emoji mandate, single language per heading/context, no bilingual parenthetical glosses (`Term (คำแปล)`).
- **Audit & Commit Logging**: Commit mutations before recording log entries; maintain short commit SHAs in logs.
- **Pre-Commit Verification**: Validate all changes using the vault linter before finalizing commits.
