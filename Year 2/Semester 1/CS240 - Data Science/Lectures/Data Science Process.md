---
type: lecture
title: The Data Science Lifecycle & Process
course_code: CS240
week: 2
tags:
  - data-science
  - data-science-process
  - eda
  - machine-learning
  - crispm-dm
description: Comprehensive guide to the end-to-end Data Science Process (CRISP-DM / OSEMN), from Problem Framing, Data Acquisition, EDA, Feature Engineering to Model Deployment.
---

# 🔄 The Data Science Lifecycle & Process

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS240]] > [[Data Science Process]]
> **Related Notes:** [[The Data Science]] \| [[CS240]]
> **Reference:** `Private/Docs/CS240_Week1_Principle_of_Data_Science.pdf`

---

## 1. End-to-End Data Science Lifecycle Overview

The Data Science process is an iterative lifecycle that transforms raw, messy data into actionable insights and robust predictive models, following international standards such as **CRISP-DM** (Cross-Industry Standard Process for Data Mining) and the **OSEMN Framework**:

```
 ┌─────────────────┐      ┌──────────────────┐      ┌──────────────────┐
 │ 1. Problem      │ ───► │ 2. Data          │ ───► │ 3. Data          │
 │    Framing      │      │    Acquisition   │      │    Preparation   │
 └─────────────────┘      └──────────────────┘      └────────┬─────────┘
                                                             │
 ┌─────────────────┐      ┌──────────────────┐               │
 │ 6. Deployment   │ ◄─── │ 5. Modeling      │ ◄─── ┌────────▼─────────┐
 │    & Story      │      │    & Evaluation  │      │ 4. Exploratory   │
 └─────────────────┘      └──────────────────┘      │    Analysis(EDA) │
                                                    └──────────────────┘
```

---

## 2. Step-by-Step Methodology

### 🎯 Step 1: Problem Framing & Business Understanding
- Define project objectives clearly, concisely, and measurably.
- Translate business questions into formal data science formulations (e.g., Binary/Multi-class Classification, Regression, Clustering, Anomaly Detection).
- Establish Key Performance Indicators (KPIs) and project success metrics.

---

### 📥 Step 2: Data Acquisition & Ingestion
- Harvest data across heterogeneous sources:
  - **Internal Data Assets:** Relational databases (SQL/RDBMS), Data Warehouses, CRM/ERP systems, application log streams.
  - **External Data Assets:** Open repositories (Kaggle, Data.gov, UCI ML), Web Scraping, RESTful Web APIs, Third-party vendors.
- Enforce data governance, ethical compliance, and privacy regulations (GDPR / PDPA).

---

### 🧹 Step 3: Data Preparation & Preprocessing
*(Typically accounts for 60–80% of project time in real-world workflows)*
1. **Handling Missing Values:**
   - Deletion: Dropping sparse rows or features.
   - Imputation: Statistical imputation (Mean, Median, Mode) or predictive algorithms (KNN Imputer, Iterative Imputer).
2. **Handling Outliers:**
   - Statistical detection using Z-score thresholds or Interquartile Range (IQR / Boxplots).
3. **Data Type Casting & Sanitization:**
   - Casting string dates into standard Datetime formats, stripping whitespace, resolving formatting discrepancies.
4. **Deduplication:**
   - Identifying and purging redundant or duplicate records.

---

### 🔍 Step 4: Exploratory Data Analysis (EDA)
- **Descriptive Statistics:** Measures of central tendency (Mean, Median) and dispersion (Standard Deviation, Variance, Skewness, Kurtosis).
- **Distribution Analysis:** Histograms, KDE Density plots, Q-Q plots for normality testing.
- **Correlation & Feature Relationships:**
  - Correlation heatmaps (Pearson linear correlation, Spearman rank correlation).
  - Scatter plots, pairplots, and cross-tabulations to uncover hidden interactions and validate assumptions.

---

### ⚙️ Step 5: Feature Engineering & Selection
1. **Feature Transformation:**
   - Feature scaling: **Normalization** (Min-Max Scaling to $[0, 1]$), **Standardization** (Z-Score Scaling with $\mu=0, \sigma=1$).
   - Log transformation to handle skewed distributions.
2. **Categorical Feature Encoding:**
   - **One-Hot Encoding** for nominal unordered categorical variables.
   - **Ordinal / Label Encoding** for structured ranking categories.
3. **Feature Selection:** Filter, wrapper, and embedded methods to eliminate collinear features and mitigate the Curse of Dimensionality.

---

### 🤖 Step 6: Model Building & Evaluation
1. **Data Splitting:** Partition dataset into Training, Validation, and Test subsets (e.g., 70:15:15 or 80:20 split) alongside **K-Fold Stratified Cross-Validation**.
2. **Model Training:** Fit appropriate candidate algorithms:
   - *Supervised Learning:* Linear/Logistic Regression, Decision Trees, Random Forest, Gradient Boosting (XGBoost, LightGBM), Neural Networks.
   - *Unsupervised Learning:* K-Means, DBSCAN, Principal Component Analysis (PCA).
3. **Evaluation Metrics:**
   - **Classification:** Confusion Matrix, Accuracy, Precision, Recall, F1-Score, ROC-AUC curve.
   - **Regression:** Mean Squared Error (MSE), Root Mean Squared Error (RMSE), Mean Absolute Error (MAE), $R^2$ Score.

---

### 🚀 Step 7: Deployment, Monitoring & Storytelling
- **Model Deployment:** Package models (Pickle, ONNX) and expose via REST APIs (FastAPI, Flask) or cloud microservices.
- **Continuous Monitoring:** Track model latency, throughput, Data Drift, and Concept Drift over time.
- **Data Storytelling:** Communicate strategic business insights and model interpretations to stakeholders via interactive dashboards and visual presentations.

---

## 🐍 Python Lab Exercises in Vault

Hands-on notebooks corresponding to the workflow above are located in `Labs/Week2/`:
1. `Labs/Week2/02-1_KU-Eng_TUCS_Python_Basic_Data-Structures.ipynb` — Fundamental Python structures (Lists, Tuples, Dicts, Sets)
2. `Labs/Week2/03-1_The-Basics-Of-NumPy-Arrays.ipynb` — Multidimensional array manipulation and vectorized computations with NumPy
3. `Labs/Week2/04-1_Pandas_Basics.ipynb` — Tabular data manipulation using Pandas Series and DataFrames
4. `Labs/Week2/04-2_Pandas_Basics_Data_Indexing_and_Selection.ipynb` — Advanced filtering and data selection with `.loc` and `.iloc`

---

## 🔗 Related Notes & References
- [[CS240]] — Main Course Index for Data Science
- [[The Data Science]] — Introduction to Data Science and analytics maturity levels
