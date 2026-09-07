

# TaskForge — Emergency Incident & Task Management System

**COS214 Practical 4 (2026)**

TaskForge is a reusable, object-oriented work-processing framework implemented in **C++11**. Modeled around an **Emergency Incident & Response Management** domain, the system models complex hierarchical operations, dynamic lifecycle states, stackable runtime responsibilities, and flexible hierarchy traversals using four core Gang of Four (GoF) design patterns.

---

## 🛠️ Design Patterns Architecture

The system seamlessly integrates four GoF structural and behavioral design patterns:

* **Composite Pattern (`ResponseWorkItem`):**
* **Component:** `ResponseWorkItem` (polymorphic base interface with virtual destructors).
* **Composite:** `IncidentGroup` (holds nested groups and individual work items).
* **Leaves:** Concrete operational tasks such as `RescueTask` and `MedicalTask` (derived via `ResponseTask`).


* **State Pattern (`TaskState`):**
* Manages the lifecycle of a `ResponseTask` across concrete states: `ReportedState` $\rightarrow$ `EnRouteState` $\rightarrow$ `ActiveState` $\rightarrow$ `CompletedState`.
* Enforces state-dependent behavior and prevents invalid transitions.


* **Decorator Pattern (`WorkItemDecorator`):**
* Dynamically stacks additional runtime responsibilities onto any `ResponseWorkItem` without modifying underlying concrete classes.
* Concrete Decorators: `RapidTriageDecorator`, `InterAgencySyncDecorator`, and `HazardEscalationDecorator`.


* **Iterator Pattern (`WorkItemIterator`):**
* Encapsulates structural traversal without exposing the underlying container structure to client code.
* Concrete Iterators: `FullOperationalSweepIterator` (complete hierarchy traversal) and `MedicalPriorityIterator` (selective domain traversal).



---

## 📁 Repository Structure

```text
.
├── include/           # Header files (.h) with include guards
├── src/               # Implementation files (.cpp)
├── Makefile           # Build automation script
└── README.md          # Project documentation

```

---

## 🚀 Build & Execution Instructions

This project is configured to run inside the supplied Docker environment using `g++` with standard C++11 flags.

### 1. Compilation

Clean previous build artifacts and compile the system:

```bash
make clean && make

```

### 2. Execution

Run the compiled application:

```bash
./main

```

### 3. Memory & Debugging Verification

To verify clean polymorphic destruction, zero memory leaks, and valid pointer management as required by the specification:

```bash
# Run with Valgrind leak check
valgrind --leak-check=full --show-leak-kinds=all ./main

# Debug using GDB
gdb ./main

```

---

## 🏛️ Design & Ownership Principles

* **Polymorphic Destruction:** All abstract base classes (`ResponseWorkItem`, `TaskState`, `WorkItemDecorator`, `WorkItemIterator`) declare virtual destructors to ensure clean memory deallocation across polymorphic hierarchies.
* **Ownership Policy:** `IncidentGroup` explicitly owns its direct child pointers and manages their destruction. `ResponseTask` strictly manages and deletes its allocated `TaskState` during state transitions and object cleanup.
