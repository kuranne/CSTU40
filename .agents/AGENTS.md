# AGENTS.md

## Overview
This repository functions as a highly integrated, personal academic book structure and learning vault. It houses coursework materials, assignments, lab exercises, projects, and lecture notes across several semesters for Year 1 and Year 2. 

The primary objective of AI agents working in this repository is to assist with **summarization**, **organization**, and **relational knowledge management** to enhance active learning. Agents are also authorized and expected to **maintain their own configuration files** (under the `.agent/` and `.agents/` directories) to optimize their workflows over time.

---

## Workspace Directory Map
The book/vault is organized chronologically by academic years and semesters. Follow this flat directory map to navigate and place assets:

```
.
├── Assets/                       # Global assets folder
│   ├── Private/                  # Personal documents, certificates, and private PDFs
│   │   ├── Certificate/          # Verified credentials and hackathon certificates
│   │   ├── Docs/                 # Personal CV, transcripts, and official documentation
│   │   └── Pictures/             # Personal profile pictures and visual identities
│   └── Sairahud/                 # Low-level systems work and Assembly language source payloads
│
│
├── Year 1/                       # Academic materials for the first year
│   ├── Career/                   # Entrance exams, regulations, and tuition declarations
│   │   └── Private/              # Protected admissions and registration files
│   │
│   ├── Semester 1/               # Year 1, Semester 1 Course vaults
│   │   ├── CS100 - Basic Web Development/
│   │   │   ├── Assignments/      # Web assignments (HTML, CSS, peer reviews, challenges)
│   │   │   ├── Labs/             # Exercises (Bootstrap, CSS layouts, PHP, Nginx, Docker)
│   │   │   ├── Lectures/         # CS100.md (Ignore non-class-code items here)
│   │   │   └── Projects/         # Final website projects (e.g., Final - Street Booth)
│   │   │
│   │   ├── CS101 - Discrete Math/
│   │   │   ├── Assignments/      # Assignment sheets and problem solutions
│   │   │   └── Lectures/         # Discrete Math notes (CS101.md - Ignore non-class-code)
│   │   │
│   │   ├── CS102 - Basic Programming/
│   │   │   ├── Assignments/      # Homeworks (C language source codes)
│   │   │   ├── Exam/             # Practical exam problems (C files)
│   │   │   ├── Labs/             # Weekly laboratory practices (C source files)
│   │   │   └── Lectures/         # Array, Condition, Enum, Function, Pointer, Stdio, String, Struct, etc.
│   │   │                         # NOTE: Keep/manage folders containing C class code files here.
│   │   │
│   │   ├── LAS101 - Critical Thinking/
│   │   │   ├── Assignments/      # Logic, teamwork, and reasoning essays (Docx/PDF)
│   │   │   └── Lectures/         # Lecture notes and interpretation guides (Ignore non-class-code)
│   │   │
│   │   ├── TU107 - Digital Wellbeing/
│   │   │   ├── Assignments/      # Practical assignments, datasets, reports, and infographics
│   │   │   └── Lectures/         # Core notes (TU107.md - Ignore non-class-code)
│   │   │
│   │   └── TU109 - Enteprener Mindset/
│   │       ├── Assignments/      # Elevator pitch, final submissions, and webloc bookmarks
│   │       └── Lectures/         # Business model and mindset notes (Ignore non-class-code)
│   │
│   └── Semester 2/               # Year 1, Semester 2 Course vaults
│       ├── CS111 - Object Oriented Programming/
│       │   ├── Assignments/      # Bookstore, store, and escape-landmine programs (Java)
│       │   └── Lectures/         # Weekly Java coding files, package structure, and CS111.md
│       │                         # NOTE: Keep/manage folders containing Java class code files here.
│       │
│       ├── EL295 - English for Researching/
│       │   ├── Assignments/      # AI and daily life survey reports (Docx)
│       │   └── Lectures/         # Academic English reference notes (Ignore non-class-code)
│       │
│       ├── TU100 - Civic Engagement/
│       │   ├── Assignments/      # Social movement projects and webloc bookmarks
│       │   └── Lectures/         # Civic system notes (TU100.md - Ignore non-class-code)
│       │
│       ├── TU101 - History/
│       │   ├── Assignments/      # Historical scripts (PDF)
│       │   └── Lectures/         # Notes on Globalization, Neoliberalism, Middle Class, etc. (Ignore non-class-code)
│       │
│       ├── TU106 - Creative Thinking/
│       │   ├── Assignments/      # Reflection diaries and presentation assets
│       │   └── Lectures/         # Ideation notes (Ignore non-class-code)
│       │
│       └── TU108 - Wellbeing/
│           ├── Assignments/      # Personal goals plan and health templates
│           └── Lectures/         # Wellness notes (TU108.md - Ignore non-class-code)
│
├── Year 2/                       # Academic materials for the second year
│   ├── Career/                   # Professional development, internships, and networking
│   └── Semester 1/               # Year 2, Semester 1 Course vaults
│       ├── CS213 - Data Structure/
│       │   ├── Labs/             # C++ class code practices (Counter, Robot, IntCell)
│       │   ├── Lectures/         # C++ language and memory layout notes (Ignore non-class-code)
│       │   └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│       │       └── Docs/         # Pointer, array, and structures PDFs
│       │
│       ├── CS221 - Computer Architecture/
│       │   ├── Assets/           # Screenshot walkthroughs of memory/register architectures
│       │   ├── Labs/             # C compiles, ARM, and x86 Assembly code implementations
│       │   ├── Lectures/         # Register architecture and concurrency notes (Ignore non-class-code)
│       │   └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│       │       └── Docs/         # Microarchitecture and ISA reference PDFs
│       │
│       ├── CS240 - Data Science/
│       │   ├── Assets/           # Sepsis data files and modeling sheets
│       │   ├── Assignments/      # Jupyter Notebooks and pages data cleansing
│       │   ├── Labs/             # Python structure, NumPy, and Pandas cleansing Notebooks
│       │   ├── Lectures/         # Data processes and workflows (CS240.md - Ignore non-class-code)
│       │   └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│       │       └── Docs/         # Principles of Data Science slides (PDF)
│       │
│       ├── CS261 - Software Engineering/
│       │   ├── Lectures/         # Cost of development and linter notes (Ignore non-class-code)
│       │   └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│       │       └── Docs/         # Design and architecture PDFs
│       │
│       ├── HS369 - History of Modern Japan/
│       │   ├── Assets/           # Historical map screenshots and photos of Hiroshima
│       │   ├── Lectures/         # Post-war Japan notes (HS369.md - Ignore non-class-code)
│       │   └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│       │       └── Docs/         # Contemporary Japanese history materials
│       │
│       ├── PY252 - Psychology/
│       │   ├── Assets/           # Conceptual graphs and templates
│       │   ├── Lectures/         # Gender differences and human relationships notes (Ignore non-class-code)
│       │   └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│       │       └── Docs/         # Human needs, motivation, and difference models (PDFs)
│       │
│       └── ST329 - Stats for Data Science/
│           ├── Lectures/         # Probability theory notes (ST329.md - Ignore non-class-code)
│           └── Private/          # Protected university assets (Gitignored via **/[Pp]rivate/**)
│               └── Docs/         # Probability theory lecture PDFs
│
├── .agent/                       # Local directory for agent-specific profiles and memory
│   ├── log/                      # Local agent runtime execution and session logs (*.log)
│   └── *.agent.md                # Specialized custom agent personas (e.g., summarizer, organizer)
└── .agents/                      # Shared workspace configurations (manifests, security policies, skills)
    ├── log/                      # Shared workspace change records and audit trails (*.log)
    ├── skills/                   # Reusable agent skills and domain guidelines
    │   ├── obsidian-expert-skill.md # Master Obsidian authoring standard
    │   ├── latex-math-skill.md      # Comprehensive LaTeX & MathJax mathematical notation guide
    │   └── mermaid-diagram-skill.md # Complete Mermaid diagram specification & templates
    └── AGENTS.md                 # Master operational guidelines and repository architecture
```

> 💡 **Lecture Folder Constraints**: When analyzing `Lectures/` subdirectories, **completely ignore** study notes, presentations, or miscellaneous files **unless they are directories or files containing class code** (such as `.c`, `.cpp`, `.java`, `.cpp`, `.h`, `.arm`, `.x86`, or `.ipynb` source files). Other miscellaneous lecture files can be anything and are irrelevant to programmatic structures.

---

## Core Task Guidelines

### 1. Summarization Workflows (`When summary:`)
When asked to summarize courses, notes, or codebases, follow these strict parameters:
*   **Keep Writing Style**: Do not standardize or dryly sanitize the author's voice. Preserve the native formatting habits, tone, and formatting idioms of the student's original documents.
*   **Keep Original Language**: Summaries of Thai notes or code comments must remain in **Thai**, and summaries of English materials must remain in **English**. Do not translate unless explicitly requested.
*   **Internet-Driven Enrichment**: When synthesizing a topic, you are authorized to search the web for external references. You may download, generate, or insert:
    *   Related illustrations, diagrams, or flowcharts (saving them directly under the course's `Assets/` or a related folder).
    *   Markdown cheat sheets (`.md` files) summarizing standard APIs or mathematical formulas.
    *   Standard source code examples, sample files, or boilerplates to enrich assignments or labs.

### 2. Organization Workflows (`When organize:`)
When asked to clean up, structure, index, or link files in the vault:
*   **Knowledge-Graph Mapping**: Proactively connect related topics together across semesters or courses. For example:
    *   Link `CS213 - Data Structure/` back to foundational C coding in `CS102 - Basic Programming/`.
    *   Link `CS240 - Data Science/` concepts to statistics in `ST329 - Stats for Data Science/`.
    *   Always write these connections using Obsidian wikilink syntax: `[[Note Name]]` or alias links `[[Note Name|Display Label]]`.
*   **Obsidian-Expert Standards**: All notes must be written in strict compliance with the **Obsidian Expert AI Agent Skill** (`obsidian-expert-skill.md`). This includes:
    *   Adding properly typed YAML frontmatter properties enclosed in triple-dashes (`---`) at the top of each `.md` file.
    *   Structuring hierarchies using proper headings (`#`, `##`).
    *   Utilizing Obsidian's visual callouts (e.g., collapsible `> [!info]+` or `> [!tip]-`) to manage density.
    *   Writing native Dataview queries (````dataview` blocks) on index notes to list, table, or task-track files dynamically.
    *   Rendering flowchart structures using native Mermaid blocks (````mermaid`).
    *   Formatting mathematics with inline (`$...$`) or block (`$$...$$`) LaTeX syntax.
*   **Zero-Waste Duplication Policy**: If the same resource, assignment description, or reference asset is needed in multiple folders, **do not write duplicate files**. You must use Unix **symbolic links (symlinks)** or **hard links** (using standard `ln` or `ln -s` commands) to cross-reference them. Maintain a single source of truth.

### 3. Agent Configuration Self-Maintenance (`let agent can maintain .agent/ themself`)
You are not a passive, static observer in this repository. You are fully authorized and expected to manage and upgrade your own operational tools and instructions:
*   **Directory Ownership**: You have full write/edit permissions inside the `.agent/` and `.agents/` folders.
*   **Persona Evolution**: Write, refine, and update custom agent profiles (`.agent.md` files) in `.agent/` to split complex tasks (e.g., creating a dedicated `summarizer.agent.md` or a `vault-organizer.agent.md`).
*   **Configuration Drift Prevention**: Run periodic checks to ensure `AGENTS.md` and related `.agent/` configuration structures are in perfect sync with the directory contents. If directories are restructured, update this `AGENTS.md` file immediately to prevent configuration drift.
*   **YAML Metadata Integrity**: Ensure any frontmatter inside `.agent.md` or configuration YAML files conforms to strict specifications, utilizing lowercase-with-hyphens naming for files.

### 4. Changelog & Execution Logging Method (`store latest changelog in ./agent(s)/log/*.log`)
To maintain operational traceability, historical auditing, and seamless rollback capability across automated workflows, agents must commit changes prior to logging and attach the resulting Git commit hash (SHA) to each log record:

*   **Execution & Commit-Before-Logging Workflow**:
    1. **Execute Changes**: Perform file creations, modifications, refactoring, or re-linking in the vault.
    2. **Git Commit Before Logging**: Stage and commit all mutated files to Git using a descriptive, structured commit message (e.g. `git add <files>` and `git commit -m "<action>: <summary>"`).
    3. **Extract Commit SHA**: Retrieve the generated Git commit hash / SHA (e.g. `git rev-parse HEAD` or short SHA `git rev-parse --short HEAD`).
    4. **Record Log with Commit SHA**: Write/append the structured changelog entry into `.agent/log/*.log` and `.agents/log/changelog.log`, including the `COMMIT SHA` field for rollback tracking.
*   **Log Storage & Naming Conventions**:
    *   **Agent & Task Session Logs**: Record individual execution runs in `.agent/log/` using timestamped filenames: `YYYY-MM-DD_<agent_or_task>.log` (e.g., `.agent/log/2026-08-20_vault_organizer.log`, `.agent/log/2026-08-20_summarizer.log`).
    *   **Repository-Wide Changelog**: Append continuous chronological repository changes into `.agents/log/changelog.log` or `.agent/log/latest.log`.
*   **Standard Log Format**: Each log entry must adhere to the following structured format containing the `COMMIT SHA`:
    ```log
    ================================================================================
    TIMESTAMP   : [YYYY-MM-DDTHH:mm:ssZ / Local ISO timestamp]
    COMMIT SHA  : [Git commit hash, e.g., a1b2c3d or full 40-character SHA]
    OPERATOR    : [Active Agent Persona, e.g., organizer.agent.md / summarizer.agent.md]
    ACTION TYPE : [ORGANIZE | SUMMARIZE | TRANSLATE | LINK | REFACTOR | CONFIG_UPDATE]
    TARGETS     :
      - [Path/to/modified_or_created_file_1.md]
      - [Path/to/modified_or_created_file_2.md]
    CHANGELOG   :
      - [Detailed summary of modifications, created sections, or bugfixes]
      - [Cross-links or frontmatter properties updated]
      - [External references, code examples, or assets added]
    STATUS      : [SUCCESS | PARTIAL | FAILED]
    ERRORS/NOTES: [None | Specific warning or error details]
    ================================================================================
    ```
*   **Rollback Mechanism**:
    *   Because each log entry explicitly specifies the `COMMIT SHA`, any operation can be inspected (`git show <COMMIT_SHA>`) or quickly rolled back (`git revert <COMMIT_SHA>` or `git checkout <COMMIT_SHA>~1 -- <files>`) with full precision.
*   **Operational Logging Rules**:
    *   **Atomic Logging**: Append an updated changelog entry to the relevant `.log` file immediately upon completing and committing any batch of file additions, modifications, or reorganizations.
    *   **Privacy & Secret Redaction**: Never write raw credential strings, private certificates, or personal identity information from `Assets/Private/` into log files.
    *   **Git Integration**: All log files (`*.log`) and log directories (`log/`) under `.agent/` and `.agents/` are strictly ignored by Git via `.gitignore` to keep version history clean while preserving local operational logs.
    *   **Log Managing**: When the number of log in changelog reach or exceed 16, use `tar -cJf` to compress them. Use ISO8601 timestamp keep them on `.agents/log/`. And after number of compress reach or exceed 16, delete the older else.

---

## Boundaries & Operational Safety

*   ✅ **Always Do**: 
    *   Adhere to `obsidian-expert-skill.md` for formatting any markdown document in this vault.
    *   Create symlinks/hardlinks for any asset that belongs in multiple locations.
    *   Preserve original languages and writing styles when generating summaries.
    *   Update this `AGENTS.md` file if the directory structure changes or new courses are added.
    *   **University Assets & Copyright Protection**: Store all university lecture slide decks, official course handouts, PDFs, and instructor materials under `<Class>/Private/Docs/` so they remain protected by the `**/[Pp]rivate/**` gitignore pattern.
    *   **Commit Before Logging**: Always commit mutated files to Git before recording logs, and include the generated `COMMIT SHA` in the log entry for easy rollback.
    *   Append latest changelogs and operational records to `.agent/log/*.log` or `.agents/log/*.log` after mutating operations.
*   ⚠️ **Ask First**:
    *   Before performing bulk folder restructures outside of Year/Semester groupings.
    *   Before deleting old, deprecated assignment drafts (prefer archiving them first).
*   🚫 **Never Do**:
    *   **Never use standard relative markdown links** (e.g., `[Note](../Note.md)`) for internal vault connections; standard relative paths break Obsidian's internal graph visualization. Always use Wikilinks.
    *   **Never commit raw decrypted secrets**, API keys, or private credential strings to public or shared areas. Keep private assets under `.gpg` or properly gitignored.
    *   **Never touch, modify, or delete** the `.git/` directory or global system parameters that could destabilize the environment.
