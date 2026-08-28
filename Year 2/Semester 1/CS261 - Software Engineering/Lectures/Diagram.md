---
type: lecture
title: "UML Diagrams & Mermaid Syntax Complete Reference"
course_code: CS261
week: 4
tags:
  - software-engineering
  - uml-diagrams
  - software-design
  - architectural-modeling
  - mermaid-syntax
  - cstu40
description: "Comprehensive guide to all 14 UML 2.5 standard diagrams (Structural and Behavioral) with theoretical foundations, notation conventions, and copy-pasteable Mermaid syntax examples."
---

# 📐 UML Diagrams & Mermaid Syntax Complete Reference

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS261]] > [[Diagram]]
> **Related Notes:** [[CS261]] \| [[Introduction to Software Engineering]] \| [[Software Process]] \| [[System Engineer]] \| [[Cost of Development]]

---

## 1. Overview of UML (Unified Modeling Language)

The **Unified Modeling Language (UML)** is an ISO/IEC and OMG (Object Management Group) standard visual modeling language used in software engineering to **specify**, **visualize**, **construct**, and **document** the artifacts of object-oriented software-intensive systems.

```
                                 ┌───────────────────────────────┐
                                 │       UML 2.5 Diagrams        │
                                 │         (14 Diagrams)         │
                                 └───────────────────────────────┘
                                                 │
                  ┌──────────────────────────────┴──────────────────────────────┐
                  ▼                                                             ▼
   ┌──────────────────────────────┐                              ┌──────────────────────────────┐
   │     Structural Diagrams      │                              │     Behavioral Diagrams      │
   │      (Static Structure)      │                              │      (Dynamic Behavior)      │
   │         (7 Diagrams)         │                              │         (7 Diagrams)         │
   └──────────────────────────────┘                              └──────────────────────────────┘
                  │                                                             │
    ├── 1. Class Diagram                                          ├── 8. Use Case Diagram
    ├── 2. Object Diagram                                         ├── 9. Activity Diagram
    ├── 3. Package Diagram                                        ├── 10. State Machine Diagram
    ├── 4. Component Diagram                                      └── 11. Interaction Diagrams
    ├── 5. Deployment Diagram                                           ├── 11a. Sequence Diagram
    ├── 6. Composite Structure Diagram                                  ├── 11b. Communication Diagram
    └── 7. Profile Diagram                                              ├── 11c. Timing Diagram
                                                                        └── 11d. Interaction Overview
```

> [!abstract] Core Purposes of UML in Software Engineering:
> 1. **Communication:** Serves as a universal lingua franca bridging business analysts, architects, software engineers, and QA teams.
> 2. **Abstraction & Architectural Blueprint:** Allows modeling complex distributed systems without getting entangled in low-level language syntax.
> 3. **Validation & Verification:** Validates requirements, edge-case lifecycles, and system states before writing production code.
> 4. **Forward & Reverse Engineering:** Facilitates generating code skeleton from diagrams and reverse-documenting existing systems.

---

## 2. Classification Matrix: Structural vs. Behavioral

| Category | Diagram Name | Primary Focus / Objective | Mermaid Opener |
| :--- | :--- | :--- | :--- |
| **Structural** | **1. Class Diagram** | Static structure of classes, attributes, methods, and relationships. | `classDiagram` |
| **Structural** | **2. Object Diagram** | Snapshot of object instances and runtime values at a specific instant $t_0$. | `classDiagram` / `flowchart TD` |
| **Structural** | **3. Package Diagram** | Grouping of classes into namespaces, subsystems, and architectural layers. | `flowchart TD` (subgraphs) |
| **Structural** | **4. Component Diagram** | Modular components, provided/required interfaces (lollipops/sockets). | `flowchart TD` / `flowchart LR` |
| **Structural** | **5. Deployment Diagram** | Physical hardware nodes, virtual environments, containers, and network links. | `flowchart TD` (subgraphs) |
| **Structural** | **6. Composite Structure** | Internal decomposition of a classifier, including ports, parts, and connectors. | `flowchart LR` (subgraphs) |
| **Structural** | **7. Profile Diagram** | Metamodel customization via stereotypes (`<<...>>`), tagged values, constraints. | `classDiagram` / `flowchart TD` |
| **Behavioral** | **8. Use Case Diagram** | User goals, system boundary, actors, and functional scopes (`include`/`extend`). | `flowchart LR` (subgraphs) |
| **Behavioral** | **9. Activity Diagram** | Step-by-step procedural workflow, concurrency forks/joins, and swimlanes. | `flowchart TD` / `flowchart LR` |
| **Behavioral** | **10. State Machine Diagram** | Finite states, event triggers, guards, actions, and lifecycle transitions. | `stateDiagram-v2` |
| **Behavioral** | **11. Sequence Diagram** | Chronological, time-ordered message interchange between lifelines. | `sequenceDiagram` |
| **Behavioral** | **12. Communication Diagram** | Object interactions focused on architectural link topology and numbered messages. | `flowchart TD` |
| **Behavioral** | **13. Timing Diagram** | State/value transitions plotted against a continuous, linear time scale. | `gantt` / `flowchart LR` |
| **Behavioral** | **14. Interaction Overview** | High-level macro workflow containing embedded sequence/interaction frames. | `flowchart TD` (subgraphs) |

---

# Part I: Structural UML Diagrams (ไดอะแกรมเชิงโครงสร้าง)

---

### 1. Class Diagram (คลาสไดอะแกรม)

> [!info] Concept & Purpose
> The **Class Diagram** is the cornerstone of object-oriented modeling. It models the static structure of a system by showing the system's classes, their attributes, operations (methods), visibility, and the relationships among objects.

#### Key Notations & Relationships
- **Visibility Modifiers:** `+` (Public), `-` (Private), `#` (Protected), `~` (Package/Default).
- **Inheritance / Generalization (`<|--`):** Child class inherits from parent class (`Is-a`).
- **Realization / Implementation (`<|..`):** Concrete class implements interface contract.
- **Composition (`*--`):** Strong whole-part relationship where parts **cannot exist** without the whole (owned lifecycle).
- **Aggregation (`o--`):** Weak whole-part relationship where parts **can exist** independently.
- **Association (`-->` or `--`):** General semantic relationship between two classes.
- **Dependency (`..>`):** Temporary usage where class A depends on class B (e.g. method parameter).

#### Mermaid Syntax & Implementation

```mermaid
classDiagram
    direction TB

    class User {
        <<abstract>>
        #String userId
        #String username
        #String email
        +login(String password) bool
        +logout() void
    }

    class Customer {
        -String shippingAddress
        -double balance
        +placeOrder(Cart cart) Order
        +addPaymentMethod(PaymentMethod method) void
    }

    class Order {
        -String orderId
        -DateTime orderDate
        -OrderStatus status
        -double totalAmount
        +calculateTotal() double
        +cancelOrder() bool
    }

    class OrderItem {
        -int quantity
        -double price
        +getSubtotal() double
    }

    class Product {
        -String sku
        -String name
        -double unitPrice
        -int stockQuantity
        +isAvailable(int qty) bool
    }

    class PaymentProcessor {
        <<interface>>
        +processPayment(double amount)* bool
        +refund(String transactionId)* bool
    }

    class StripePaymentService {
        -String apiKey
        +processPayment(double amount) bool
        +refund(String transactionId) bool
    }

    %% Relationships
    User <|-- Customer : Generalization (Inheritance)
    Customer "1" --> "0..*" Order : Places (Association)
    Order "1" *-- "1..*" OrderItem : Contains (Composition)
    OrderItem "0..*" --> "1" Product : Refers to (Association)
    PaymentProcessor <|.. StripePaymentService : Realization (Implements)
    Order ..> PaymentProcessor : Uses (Dependency)
```

---

### 2. Object Diagram (ออบเจกต์ไดอะแกรม)

> [!info] Concept & Purpose
> An **Object Diagram** represents a static snapshot of the system's runtime state at a specific moment in time ($t = t_0$). It instantiates classes into concrete objects, shows specific attribute values, and depicts the actual links connecting those instances.

#### Key Notations
- **Object Notation:** `instanceName : ClassName` or `: ClassName` (anonymous instance).
- **Underlined Name:** Indicates an instantiated entity.
- **State Values:** `attribute = value` (e.g., `status = "Paid"`).

#### Mermaid Syntax & Implementation

```mermaid
classDiagram
    direction LR

    class JohnCustomer {
        userId = "USR-9941"
        username = "john_doe"
        shippingAddress = "99 Phahonyothin Rd, Pathum Thani"
        balance = 450.00
    }

    class CurrentOrder {
        orderId = "ORD-2026-0828"
        orderDate = "2026-08-28 14:30"
        status = "Processing"
        totalAmount = 1250.00
    }

    class Item1 {
        sku = "TECH-KB-01"
        quantity = 1
        price = 750.00
    }

    class Item2 {
        sku = "TECH-MS-02"
        quantity = 2
        price = 250.00
    }

    class ActivePayment {
        provider = "Stripe"
        transactionId = "tx_9a8b7c6d"
        status = "Authorized"
    }

    JohnCustomer --> CurrentOrder : has placed
    CurrentOrder --> Item1 : contains
    CurrentOrder --> Item2 : contains
    CurrentOrder --> ActivePayment : settled by
```

---

### 3. Package Diagram (แพ็กเกจไดอะแกรม)

> [!info] Concept & Purpose
> A **Package Diagram** organizes the system's structural elements into logical groups, folders, namespaces, or layers. It highlights architectural boundaries, subsystem hierarchies, and dependencies (`<<use>>`, `<<import>>`, `<<access>>`) across Clean Architecture or Layered Architecture tiers.

#### Key Notations
- **Package Box:** Folder icon with a tab containing the package name.
- **Dependency Arrow (`..>`):** Indicates that elements in one package rely on elements in another.
- **Architectural Rules:** Top-down layered dependency without cyclic dependencies ($A 	o B 	o C$).

#### Mermaid Syntax & Implementation

```mermaid
flowchart TD
    subgraph PresentationLayer ["📦 Presentation Tier (UI & Controllers)"]
        WebControllers["AuthControllers<br/>OrderControllers<br/>ProductControllers"]
        ViewTemplates["REST API Endpoints<br/>JSON Serialization"]
    end

    subgraph ApplicationLayer ["📦 Application & Domain Tier (Business Logic)"]
        Services["UserService<br/>OrderProcessingService<br/>PaymentService"]
        DomainEntities["Entities: User, Order, Product<br/>Value Objects: Money, Address"]
        DomainInterfaces["Repositories Interfaces<br/>Domain Event Listeners"]
    end

    subgraph InfrastructureLayer ["📦 Infrastructure Tier (External Adapters)"]
        DatabaseAdapters["PostgreSQL Repository Impl<br/>Redis Cache Adapter"]
        ExternalServices["Stripe Payment Gateway<br/>SendGrid Email Client"]
    end

    subgraph CommonCore ["📦 Core Kernel & Shared Utilities"]
        Utilities["Exceptions & Logger<br/>Security & JWT Validator"]
    end

    PresentationLayer -. "«use»" .-> ApplicationLayer
    ApplicationLayer -. "«import»" .-> CommonCore
    InfrastructureLayer -. "«realizes»" .-> ApplicationLayer
    InfrastructureLayer -. "«use»" .-> CommonCore
```

---

### 4. Component Diagram (คอมโพเนนต์ไดอะแกรม)

> [!info] Concept & Purpose
> A **Component Diagram** describes the organization and wiring of modular, replaceable software units (components). It models high-level service interfaces using **Provided Interfaces** (Lollipops / what the component offers) and **Required Interfaces** (Sockets / what the component needs from others).

#### Key Notations
- **Component Box:** Stereotyped as `«component»`.
- **Provided Interface:** Open circle on a stick (`-O-`) representing services supplied to consumers.
- **Required Interface:** Half-circle socket (`-( `) representing services consumed from external components.
- **Port:** Small square representing an explicit interaction gateway.

#### Mermaid Syntax & Implementation

```mermaid
flowchart LR
    subgraph ClientSpace ["Client Application"]
        WebApp["«component»<br/><b>Web SPA Client</b>"]
    end

    subgraph APISpace ["Edge API Layer"]
        APIGateway["«component»<br/><b>API Gateway / Reverse Proxy</b>"]
    end

    subgraph Microservices ["Microservices Core"]
        AuthComp["«component»<br/><b>Auth Service</b><br/>Port 8081"]
        OrderComp["«component»<br/><b>Order Service</b><br/>Port 8082"]
        PaymentComp["«component»<br/><b>Payment Service</b><br/>Port 8083"]
    end

    subgraph MessagingData ["Event Bus & Storage Tier"]
        KafkaBus["«component»<br/><b>Kafka Event Stream</b>"]
        DBCluster[("«component»<br/><b>PostgreSQL DB</b>")]
    end

    WebApp -->|HTTPS REST| APIGateway
    APIGateway -->|Route: /auth| AuthComp
    APIGateway -->|Route: /orders| OrderComp
    APIGateway -->|Route: /pay| PaymentComp

    OrderComp -.->|Verify Token| AuthComp
    OrderComp -->|Publish: OrderCreated| KafkaBus
    PaymentComp -.->|Consume: OrderCreated| KafkaBus
    PaymentComp -->|Write Transactions| DBCluster
    OrderComp -->|Persist Order State| DBCluster
```

---

### 5. Deployment Diagram (ดีพลอยเมนต์ไดอะแกรม)

> [!info] Concept & Purpose
> A **Deployment Diagram** models the physical or virtual computing hardware architecture, network topology, runtime execution environments (Kubernetes, JVM, Docker), and the concrete software **artifacts** (`.jar`, `.dockerfile`, `.war`, `.exe`) deployed onto them.

#### Key Notations
- **Node (3D Box):** Physical machine, VM, or cloud server (`«device»` or `«executionEnvironment»`).
- **Artifact:** Software binary or configuration bundle (`«artifact» app.jar`).
- **Communication Path:** Solid line labeled with protocols (`TCP/IP`, `HTTPS`, `gRPC`, `AMQP`).

#### Mermaid Syntax & Implementation

```mermaid
flowchart TD
    subgraph CloudDNS ["«device» Cloudflare CDN / DNS"]
        EdgeWorker["Edge SSL & DDoS Shield"]
    end

    subgraph CloudVPC ["«cloud infrastructure» AWS VPC (ap-southeast-1)"]
        subgraph PublicSubnet ["Public Subnet (DMZ)"]
            ALB["«device» Application Load Balancer (ALB)"]
        end

        subgraph PrivateAppSubnet ["Private Subnet (Kubernetes EKS Cluster)"]
            subgraph Node1 ["«node» Worker Node EC2 #1"]
                PodAuth["«artifact» <b>auth-service.jar</b><br/>(Docker Container)"]
                PodOrder["«artifact» <b>order-service.jar</b><br/>(Docker Container)"]
            end

            subgraph Node2 ["«node» Worker Node EC2 #2"]
                PodPay["«artifact» <b>payment-service.jar</b><br/>(Docker Container)"]
                PodNotification["«artifact» <b>notifier-service.py</b><br/>(Docker Container)"]
            end
        end

        subgraph PrivateDataSubnet ["Private Database Subnet"]
            RDS_Primary[("«executionEnvironment»<br/><b>Amazon RDS PostgreSQL</b><br/>(Primary Multi-AZ)")]
            Redis_Cluster[("«executionEnvironment»<br/><b>ElastiCache Redis</b><br/>(Cluster Mode)")]
        end
    end

    EdgeWorker -->|HTTPS / TLS 1.3| ALB
    ALB -->|HTTP/2 internal| PodAuth
    ALB -->|HTTP/2 internal| PodOrder
    ALB -->|HTTP/2 internal| PodPay

    PodAuth -->|TCP / Port 6379| Redis_Cluster
    PodOrder -->|JDBC / SSL Port 5432| RDS_Primary
    PodPay -->|JDBC / SSL Port 5432| RDS_Primary
    PodPay -.->|gRPC Async| PodNotification
```

---

### 6. Composite Structure Diagram (คอมโพสิตสตรัคเจอร์ไดอะแกรม)

> [!info] Concept & Purpose
> A **Composite Structure Diagram** looks *inside* a complex classifier or system component to depict its internal structural decomposition. It details internal **parts**, **ports** (interaction endpoints), **connectors**, and collaborating roles that collaborate during runtime execution.

#### Key Notations
- **Port (`p1`):** A distinct interaction point between the classifier and its external environment.
- **Part:** Internal structural role or subsystem instance within the classifier.
- **Connector:** Communication line connecting internal parts or routing ports to internal parts.

#### Mermaid Syntax & Implementation

```mermaid
flowchart LR
    subgraph HTTPServerClassifier ["«classifier» <b>HighPerformanceHTTPServer</b>"]
        direction TB

        subgraph Ports ["Edge Ports"]
            Port80["Port 80 (HTTP)"]
            Port443["Port 443 (HTTPS)"]
        end

        subgraph InternalEngine ["Internal Architecture"]
            SSLEngine["<b>part: sslHandler</b><br/>[TLS 1.3 Decryptor]"]
            RequestRouter["<b>part: router</b><br/>[Trie Radix Matcher]"]
            ThreadPool["<b>part: workerPool</b><br/>[FixedThreadPool(128)]"]
            CacheLayer["<b>part: memCache</b><br/>[LRU Memory Cache]"]
        end

        subgraph OutboundPorts ["Outbound Database Port"]
            PortDB["Port DB_CONN (Pool: 30)"]
        end

        Port443 -->|Raw Encrypted Stream| SSLEngine
        SSLEngine -->|Plain HTTP Request| RequestRouter
        Port80 -->|Direct HTTP Request| RequestRouter

        RequestRouter -->|Check Cache| CacheLayer
        RequestRouter -->|Dispatch Task| ThreadPool
        ThreadPool -->|Execute Query| PortDB
    end

    ClientDevice(("External Client")) -->|TLS Traffic| Port443
    PortDB --> DatabaseNode[("External Database")]
```

---

### 7. Profile Diagram (โพรไฟล์ไดอะแกรม)

> [!info] Concept & Purpose
> A **Profile Diagram** provides an extension mechanism for customizing standard UML metamodels for specific domains, architectural platforms, or programming frameworks (e.g., Spring Boot, Java Enterprise, Embedded Real-Time systems, Cloud-Native Microservices).

#### Key Notations
- **Stereotype (`«stereotype»`):** An extension element that customizes a standard UML metaclass.
- **Metaclass (`«metaclass»`):** The foundational UML element being extended (e.g., `Class`, `Property`, `Component`).
- **Tagged Values / Attributes:** Domain-specific configuration metadata.
- **Extension Link (`«extension»` with filled triangle):** Arrow pointing from the Stereotype to the Base Metaclass.

#### Mermaid Syntax & Implementation

```mermaid
classDiagram
    direction TB

    class ClassMetaclass {
        <<metaclass>>
        +name: String
        +isAbstract: Boolean
    }

    class ComponentMetaclass {
        <<metaclass>>
        +isIndirectlyInstantiated: Boolean
    }

    class RestController {
        <<stereotype>>
        +path: String
        +produces: String = "application/json"
    }

    class Service {
        <<stereotype>>
        +transactional: Boolean = true
        +scope: String = "singleton"
    }

    class Entity {
        <<stereotype>>
        +tableName: String
        +schema: String = "public"
    }

    class Microservice {
        <<stereotype>>
        +serviceName: String
        +healthCheckPort: int
        +replicas: int = 3
    }

    RestController --> ClassMetaclass : «extension»
    Service --> ClassMetaclass : «extension»
    Entity --> ClassMetaclass : «extension»
    Microservice --> ComponentMetaclass : «extension»
```

---

# Part II: Behavioral UML Diagrams (ไดอะแกรมเชิงพฤติกรรม)

---

### 8. Use Case Diagram (ยูสเคสไดอะแกรม)

> [!info] Concept & Purpose
> A **Use Case Diagram** captures the functional requirements of a system from the perspective of external actors. It depicts the system boundary, primary/secondary actors, and use cases (system capabilities), highlighting inclusion and extension relationships.

#### Key Notations & Rules
- **Actor:** Stick figure or box representing human users, external systems, or time triggers.
- **Use Case:** Oval representing a distinct, measurable goal delivered by the system.
- **System Boundary:** Box enclosing all use cases belonging to the system.
- **`«include»`:** Mandatory subroutine; Base use case **always** executes the included use case (Directed arrow $	o$ Included).
- **`«extend»`:** Optional behavior; Extension use case executes only under specific conditional extension points (Directed arrow $	o$ Base).

#### Mermaid Syntax & Implementation

```mermaid
flowchart LR
    subgraph Actors ["External Actors"]
        Customer(("👤 Customer<br/>(Primary)"))
        Staff(("👨‍💼 Store Staff<br/>(Primary)"))
        BankSystem["🏦 Payment Gateway<br/>(Secondary System)"]
    end

    subgraph SystemBoundary ["📦 E-Commerce Web System Boundary"]
        UC1(["Browse Products"])
        UC2(["Search Catalog"])
        UC3(["Place Order"])
        UC4(["Process Payment"])
        UC5(["Apply Promo Code"])
        UC6(["Send Order Notification"])
        UC7(["Update Inventory"])
    end

    Customer --- UC1
    Customer --- UC2
    Customer --- UC3
    Staff --- UC7

    UC3 -. "«include»" .-> UC4
    UC3 -. "«include»" .-> UC7
    UC5 -. "«extend» [if coupon valid]" .-> UC3
    UC4 -. "«include»" .-> UC6

    UC4 --- BankSystem
```

---

### 9. Activity Diagram (แอคทิวิตีไดอะแกรม)

> [!info] Concept & Purpose
> An **Activity Diagram** models procedural workflows, business logic, algorithmic control flows, and data transitions. It natively supports **parallel processing** (Forks and Joins) and **Swimlanes** (partitioning responsibilities across organizational roles or microservices).

#### Key Notations
- **Initial Node (`((●))`):** Starting point of the activity workflow.
- **Final Activity Node (`((◎))`):** Complete termination of the entire workflow.
- **Decision Diamond (`{?}`):** Conditional branching with mutually exclusive guard conditions (`[Yes]`, `[No]`).
- **Merge Node (`{ }`):** Re-convergence of multiple conditional paths without synchronization.
- **Fork Bar (`===`):** Single control flow splits into two or more concurrent, parallel threads.
- **Join Bar (`===`):** Synchronizes multiple parallel threads before proceeding.

#### Mermaid Syntax & Implementation

```mermaid
flowchart TD
    StartNode(( )) --> InputCredentials["User enters Email & Password"]
    InputCredentials --> CheckAuth{"Valid Credentials?"}

    CheckAuth -- "[No: Retries < 3]" --> ShowError["Display Invalid Password Error"]
    ShowError --> InputCredentials

    CheckAuth -- "[No: Retries >= 3]" --> LockAccount["Lock Account for 15 mins"]
    LockAccount --> EndFailed(( ))

    CheckAuth -- "[Yes]" --> CheckMFA{"Is MFA Enabled?"}

    CheckMFA -- "[Yes]" --> SendOTP["Send OTP Code to Authenticator App"]
    SendOTP --> InputOTP["User inputs 6-digit OTP"]
    InputOTP --> VerifyOTP{"OTP Valid & Active?"}
    VerifyOTP -- "[No]" --> ShowOTPError["Show OTP Expired Error"]
    ShowOTPError --> InputOTP
    VerifyOTP -- "[Yes]" --> ForkSync

    CheckMFA -- "[No]" --> ForkSync{{"⚡ Fork: Parallel Session Setup"}}

    %% Parallel Fork Execution
    ForkSync --> GenerateJWT["Issue Signed JWT Token"]
    ForkSync --> RecordAudit["Write Audit Log to ElasticSearch"]
    ForkSync --> UpdateLastLogin["Update last_login_timestamp in DB"]

    GenerateJWT --> JoinSync{{"⚡ Join: Synchronize Tasks"}}
    RecordAudit --> JoinSync
    UpdateLastLogin --> JoinSync

    JoinSync --> ReturnDashboard["Redirect User to Home Dashboard"]
    ReturnDashboard --> EndSuccess((( )))
```

---

### 10. State Machine / State Diagram (สเตตไดอะแกรม)

> [!info] Concept & Purpose
> A **State Machine Diagram** (Statechart) models the dynamic lifecycle of a single object or finite state machine (FSM). It illustrates the discrete states an entity undergoes in response to external events, guard conditions, and internal actions.

#### Key Notations & Syntax
- **Initial State (`[*]`):** Entry point of the state machine.
- **Final State (`[*]`):** Terminal state when the object lifecycle ceases.
- **Transition Syntax:** `SourceState --> TargetState : EventTrigger [GuardCondition] / ActionEffect`
- **Composite State:** A nested super-state containing inner sub-states.

#### Mermaid Syntax & Implementation

```mermaid
stateDiagram-v2
    [*] --> Draft : CreateOrder()

    Draft --> PendingPayment : SubmitOrder()
    Draft --> Cancelled : Discard()

    PendingPayment --> Paid : PaymentSuccess [AmountMatches] / sendReceipt()
    PendingPayment --> PaymentFailed : PaymentDeclined [InvalidCard]
    PaymentFailed --> PendingPayment : RetryPayment()
    PaymentFailed --> Cancelled : Timeout [Elapsed > 24h] / releaseHold()

    state Processing {
        [*] --> AllocatingStock
        AllocatingStock --> PickingItems : StockReserved
        PickingItems --> PackingParcel : ItemsGathered
        PackingParcel --> ReadyForDispatch : QualityCheckPassed
        ReadyForDispatch --> [*]
    }

    Paid --> Processing : DispatchToWarehouse()

    Processing --> Shipped : CarrierPickup(TrackingNumber)
    Shipped --> OutForDelivery : ArrivalAtLocalHub
    OutForDelivery --> Delivered : ConfirmSignature()

    Delivered --> ReturnRequested : RequestReturn [Days <= 30]
    ReturnRequested --> Refunded : ItemReceivedBack / ProcessRefund()
    ReturnRequested --> Delivered : ReturnRejected

    Cancelled --> [*]
    Delivered --> [*]
    Refunded --> [*]
```

---

### 11. Sequence Diagram (ซีเควนซ์ไดอะแกรม)

> [!info] Concept & Purpose
> A **Sequence Diagram** is the most widely utilized interaction diagram. It models object interactions arranged in strict **chronological time sequence**. It emphasizes the vertical progression of time and the horizontal messages passed between collaborating lifelines.

#### Key Notations & Operators
- **Lifeline:** Vertical dashed line representing the existence of an object over time.
- **Activation Bar:** Vertical rectangle indicating when an object is actively executing a task.
- **Message Types:**
  - `->>` : Synchronous call (caller blocks waiting for response).
  - `-->>` : Return message (response payload).
  - `-)` : Asynchronous message (caller continues without blocking).
- **Interaction Combined Fragments:**
  - `alt ... else ... end` : Alternative conditional execution.
  - `opt ... end` : Optional execution (if condition is true).
  - `loop ... end` : Repeated iteration.
  - `par ... and ... end` : Parallel concurrent threads.
  - `critical ... end` : Atomic transaction (critical section).

#### Mermaid Syntax & Implementation

```mermaid
sequenceDiagram
    autonumber
    actor Client as 📱 Mobile App
    participant GW as 🛡️ API Gateway
    participant Auth as 🔑 Auth Service
    participant Cache as ⚡ Redis Session
    participant DB as 🗄️ PostgreSQL DB

    Client->>GW: POST /api/v1/auth/login {email, password}
    activate GW

    GW->>Auth: Authenticate(credentials)
    activate Auth

    Auth->>Cache: GET session:{email}
    activate Cache
    Cache-->>Auth: null (Cache Miss)
    deactivate Cache

    Auth->>DB: SELECT * FROM users WHERE email = ? LIMIT 1
    activate DB
    DB-->>Auth: UserRecord {id, passHash, salt, isMFA}
    deactivate DB

    alt Password Matches & MFA Disabled
        Auth->>Cache: SET session:{userId} (TokenData, TTL=3600)
        activate Cache
        Cache-->>Auth: OK
        deactivate Cache

        Auth-->>GW: 200 OK {JWT_AccessToken, RefreshToken}
        GW-->>Client: 200 Success Response
    else Password Invalid
        Auth-->>GW: 401 Unauthorized {errorCode: "INVALID_CREDENTIALS"}
        GW-->>Client: 401 Unauthorized Error
    else MFA Required
        Auth-->>GW: 202 Accepted {challengeId, type: "TOTP"}
        GW-->>Client: 202 Prompt for MFA Token
    end

    deactivate Auth
    deactivate GW
```

---

### 12. Communication Diagram (คอมมิวนิเคชันไดอะแกรม)

> [!info] Concept & Purpose
> Formerly known as a **Collaboration Diagram** in UML 1.x, the **Communication Diagram** focuses on the **structural organization and architecture** of collaborating objects rather than pure time progression. Message sequencing is shown explicitly via **hierarchically numbered decimal labels** ($1, 1.1, 1.2, 2, ...$).

#### Key Notations & Numbering Conventions
- **Solid Links:** Structural communication paths between objects.
- **Numbered Messages:** E.g., `1: Request`, `1.1: Nested sub-call`, `1.2: Follow-up sub-call`, `2: Next sequential step`.
- **Directional Arrow:** Indicates the sender and recipient of each message.

#### Mermaid Syntax & Implementation

```mermaid
flowchart TD
    Client["👤 <b>Client (User)</b>"]
    Controller["⚙️ <b>:OrderController</b>"]
    OrderService["📦 <b>:OrderService</b>"]
    Inventory["🏭 <b>:InventoryManager</b>"]
    PaymentGateway["💳 <b>:PaymentGateway</b>"]
    Notification["🔔 <b>:EmailNotifier</b>"]

    Client -->|1. submitOrder(cart)| Controller
    Controller -->|1.1. processOrder(cart)| OrderService

    OrderService -->|1.1.1. reserveItems(itemList)| Inventory
    Inventory -- "1.1.1.1. confirmReservation()" --> OrderService

    OrderService -->|1.1.2. chargeCreditCard(amount)| PaymentGateway
    PaymentGateway -- "1.1.2.1. paymentApproved(txId)" --> OrderService

    OrderService -->|1.1.3. dispatchOrderReceipt()| Notification
    OrderService -- "1.2. orderSuccess(ORD-991)" --> Controller
    Controller -- "2. displayOrderSummary()" --> Client
```

---

### 13. Timing Diagram (ไทม์มิ่งไดอะแกรม)

> [!info] Concept & Purpose
> A **Timing Diagram** is a specialized interaction diagram used in real-time embedded systems, hardware design, and protocol verification. It models the **exact state changes and value conditions** of one or more lifelines along a continuous, quantitative **timeline scale** with strict duration and latency constraints.

#### Key Notations
- **State Timeline:** Horizontal waveform/line transitioning between discrete states (e.g. *Idle $	o$ Reading $	o$ Processing*).
- **Time Axis:** Quantitative scale marked in seconds, milliseconds ($	ext{ms}$), or clock cycles.
- **Timing Constraints:** Max/min duration limits (e.g., $t_{	ext{response}} < 50	ext{ms}$).

#### Mermaid Syntax & Implementation

```mermaid
gantt
    title Hardware / Software Door Access Controller Timing Lifecycle
    dateFormat X
    axisFormat %s sec

    section Sensor Hardware
    Laser Proximity Sensor (Idle)        :0, 2
    Proximity Triggered (Active High)   :active, 2, 5
    Sensor Reset to Standby             :5, 12

    section RFID Reader Firmware
    Standby Polling Mode                :0, 2
    Reading SmartCard RFID Payload       :crit, 2, 4
    Validating Payload Cryptography     :4, 5
    Card Removed (Idle Mode)            :5, 12

    section Microcontroller Logic
    MCU in Sleep Mode                   :0, 2
    Wakeup Interrupt & Decrypt Token    :crit, 2, 5
    Authorize Relay & Trigger Solenoid  :5, 9
    Relock Timeout & Power Down         :9, 12

    section Physical Solenoid Lock
    Bolt Locked (State = CLOSED)        :0, 5
    Motor Unlocked (State = OPEN)       :active, 5, 9
    Bolt Re-Engaged (State = LOCKED)    :9, 12
```

---

### 14. Interaction Overview Diagram (อินเทอร์แอคชันโอเวอร์วิวไดอะแกรม)

> [!info] Concept & Purpose
> An **Interaction Overview Diagram** provides a high-level macro view of system interactions by marrying the control-flow structure of an **Activity Diagram** with embedded **Interaction Frames** (miniature Sequence or Communication diagrams nested inside activity nodes).

#### Key Notations
- **Activity Control Nodes:** Initial node, decisions, forks, joins, merge points.
- **Interaction Use / Frame (`ref`):** A box referencing or containing a detailed sequence diagram.
- **Branching Decision:** Determines which macro interaction scenario executes.

#### Mermaid Syntax & Implementation

```mermaid
flowchart TD
    InitNode((● Start)) --> NodeAuth["<b>sd: Authentication Interaction</b><br/>Verify user credentials and active subscription status"]

    NodeAuth --> AuthDecision{"Auth Successful?"}

    AuthDecision -- "[No]" --> NodeLoginRetry["<b>sd: Error Handling Interaction</b><br/>Trigger CAPTCHA and display lockout timer"]
    NodeLoginRetry --> TerminateFailed((◎ End))

    AuthDecision -- "[Yes]" --> NodeSelectPayment{"Payment Gateway Type"}

    NodeSelectPayment -- "[Credit / Debit Card]" --> FrameCard["<b>sd: 3D-Secure 2.0 Sequence</b><br/>1. Send OTP challenge<br/>2. Bank ACS verifies biometric<br/>3. Capture settlement"]

    NodeSelectPayment -- "[PromptPay / QR Code]" --> FrameQR["<b>sd: PromptPay Realtime Sequence</b><br/>1. Generate EMVCo QR string<br/>2. Poll webhook for Bank slip<br/>3. Reconcile transaction"]

    NodeSelectPayment -- "[Apple Pay / Google Pay]" --> FrameTokenized["<b>sd: Tokenized Wallet Sequence</b><br/>1. Exchange Device Cryptogram<br/>2. Decrypt PKPaymentToken"]

    FrameCard --> MergePayment{ }
    FrameQR --> MergePayment
    FrameTokenized --> MergePayment

    MergePayment --> NodeFulfill["<b>sd: Inventory Fulfillment Interaction</b><br/>Deduct stock, print shipping label, send invoice"]
    NodeFulfill --> TerminateSuccess(((◎ Success)))
```

---

# 🚀 Bonus: Entity-Relationship Diagram (ERD) for Software Engineering

> [!tip] Practical Relevance in SE
> While the ER Diagram is formally an ISO/IEC database standard rather than a pure UML 2.5 diagram, it is universally used alongside UML Class Diagrams to bridge **Object-Oriented Domain Entities** with **Relational Database Schemas (RDBMS)**.

```mermaid
erDiagram
    USERS ||--o{ ORDERS : places
    USERS {
        uuid user_id PK "Primary Key"
        varchar email UK "Unique indexed email"
        varchar password_hash "Argon2id cryptographic hash"
        varchar first_name
        varchar last_name
        timestamp created_at
    }

    ORDERS ||--|{ ORDER_ITEMS : contains
    ORDERS {
        uuid order_id PK "Primary Key"
        uuid user_id FK "Foreign Key to USERS"
        varchar order_status "Draft, Paid, Shipped, Cancelled"
        decimal total_amount "Precision 12, Scale 2"
        timestamp placed_at
    }

    PRODUCTS ||--o{ ORDER_ITEMS : ordered_in
    PRODUCTS {
        uuid product_id PK "Primary Key"
        varchar sku UK "Unique Stock Keeping Unit"
        varchar title "Product Name"
        decimal unit_price "Unit Retail Price"
        int stock_level "Available inventory"
    }

    ORDER_ITEMS {
        uuid item_id PK "Primary Key"
        uuid order_id FK "Foreign Key to ORDERS"
        uuid product_id FK "Foreign Key to PRODUCTS"
        int quantity "Item Quantity"
        decimal price_at_purchase "Price snapshot"
    }

    ORDERS ||--o| PAYMENTS : settled_by
    PAYMENTS {
        uuid payment_id PK "Primary Key"
        uuid order_id FK "Foreign Key to ORDERS"
        varchar payment_method "CreditCard, PromptPay, PayPal"
        varchar transaction_ref UK "External Gateway Ref"
        varchar payment_status "Authorized, Captured, Refunded"
        decimal amount_paid
        timestamp settled_at
    }
```

---

## 3. Master UML Selection & Decision Matrix

When designing software architectures, use this quick-reference selection guide to pick the right diagram for each software lifecycle phase:

```
                            ┌───────────────────────────────┐
                            │    What are you modeling?     │
                            └───────────────────────────────┘
                                            │
     ┌──────────────────────┬───────────────┴───────────────┬──────────────────────┐
     ▼                      ▼                               ▼                      ▼
1. System Scope &      2. Class Structures &           3. Dynamic Flows &     4. Hardware & Cloud
   User Requirements      Database Schemas                State Transitions       Infrastructure
   - Use Case Diagram     - Class Diagram                 - Sequence Diagram      - Deployment Diagram
   - Activity Diagram     - ER Diagram                    - State Diagram         - Component Diagram
                          - Object Diagram                - Activity Diagram
```

| Modeling Question | Primary UML Diagram | Alternative / Complementary |
| :--- | :--- | :--- |
| *Who uses the system and what are the major functional goals?* | **Use Case Diagram** | User Story Mapping |
| *What are the object-oriented classes, attributes, and relationships?* | **Class Diagram** | Package Diagram |
| *How do classes map into database tables and foreign keys?* | **ER Diagram (ERD)** | Class Diagram |
| *What is the exact chronological message sequence between services?* | **Sequence Diagram** | Communication Diagram |
| *What states does an entity transition through during its lifecycle?* | **State Machine Diagram** | Activity Diagram |
| *What is the complex business logic or multi-role approval workflow?* | **Activity Diagram** | Sequence Diagram |
| *How are microservice containers mapped across cloud servers and VPCs?* | **Deployment Diagram** | Component Diagram |
| *How are code modules grouped into layers and packages?* | **Package Diagram** | Composite Structure Diagram |
| *What are the runtime objects and variable values at instant $t$?* | **Object Diagram** | Class Diagram |
| *What are the strict real-time hardware latencies and signal timing?* | **Timing Diagram** | Sequence Diagram |

---

## 🔗 Related Notes & Course References
- [[CS261]] — Main Course Index for Software Engineering
- [[Introduction to Software Engineering]] — Foundational principles and 3 dimensions of SE
- [[Software Process]] — Process models, Waterfall, Spiral, and Agile Scrum sprints
- [[System Engineer]] — 7-Stage system engineering lifecycle and component decomposition
- [[Cost of Development]] — Total Cost of Ownership and maintenance breakdown
