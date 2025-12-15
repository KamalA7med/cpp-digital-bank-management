# 🏦 Console-Based Bank Management System (C++)

A robust, console-based application developed in C++ for managing bank clients, user accounts, currencies, and transactions. The system utilizes object-oriented programming (OOP) principles, separating functionalities into various classes and header files for clean, modular, and maintainable code.

---

## ✨ Features

* **Client Management:** Add, delete, find, and update client information (Name, Account Number, Balance, etc.).
* **User Management:** Add, delete, find, and update system users (Bank Employees) with different access levels.
* **Transactions:** Deposit, Withdraw, and Transfer money between client accounts.
* **Currency Exchange:** Show list of currencies, find a currency, update currency exchange rates, and exchange currency between clients.
* **Reporting:** View lists of all clients, system users, total bank balances, and a transfer log history.
* **Login/Security:** Secure user login and registration functionality.

---

## 📁 Project Structure

The project is organized into various header files (`.h`), source files (`.cpp`), and persistent data files (`.txt`).

### 📐 Core Classes and Business Logic

| File Name | Description |
| :--- | :--- |
| `clsPerson.h` | **Base Class** for entities that represent a person (e.g., Client, User). Contains common properties like name. |
| `clsBankClient.h` | Represents a **Client** of the bank. Inherits from `clsPerson.h`. Manages client-specific data like account balance. |
| `clsUser.h` | Represents a **System User** (Bank Employee). Inherits from `clsPerson.h`. Manages user credentials and permissions. |
| `clsCurrency.h` | Represents a **Currency** object, used for tracking currency details and exchange rates. |
| `clsString.h` | A custom **Utility Class** likely for string manipulation or formatting helper functions. |
| `clsDate.h` | A custom **Utility Class** for handling and manipulating dates and times. |
| `clsUtility.h` | Contains various **General Utility Functions** (e.g., file handling, input validation, string conversion). |

### 🖥️ Screen/UI Classes

These files handle the console-based user interface for specific tasks.

| File Name | Description |
| :--- | :--- |
| `clsScreen.h` | **Base Class** for all UI screens, potentially containing methods for displaying header/footer or common UI elements. |
| `clsMainScreen.h` | The main **application entry point/menu** screen. |
| `clsLoginScreen.h` | Handles the **user login** process. |
| `clsUsersListScreen.h` | Displays the **list of all system users**. |
| `clsAddUserScreen.h` | Screen to **add a new system user**. |
| `clsDeleteUser.h` | Screen to **delete an existing system user**. |
| `clsUpdateUserScreen.h` | Screen to **update an existing system user's** details. |
| `clsFindUserScreen.h` | Screen to **find/search for a system user**. |
| `clsManageUsers.h` | A menu screen for **User Management** operations. |
| `clsClientsListScreen.h` | Displays the **list of all bank clients**. |
| `clsAddNewClient.h` | Screen to **add a new bank client**. |
| `clsDeleteClient.h` | Screen to **delete an existing bank client**. |
| `clsUpdateClient.h` | Screen to **update an existing bank client's** details. |
| `clsFindClient.h` | Screen to **find/search for a bank client**. |
| `clsTransactionsScreen.h` | A menu screen for **Transaction** operations (Deposit, Withdraw, Transfer). |
| `clsDepositeScreen.h` | Handles the **deposit** transaction process. |
| `clsWithdrawScreen.h` | Handles the **withdrawal** transaction process. |
| `clsTransferScreen.h` | Handles the **account transfer** process. |
| `clsTransferLogScreen.h` | Displays the history of all **transfer transactions**. |
| `clsTotalBalancesScreen.h` | Displays the report of **total bank balances**. |
| `clsShowListOfCurrencies.h` | Displays the **list of all available currencies** and their rates. |
| `clsFindCurrency.h` | Screen to **find/search for a specific currency**. |
| `clsUpdateCurrencyRate.h` | Screen to **update an exchange rate** for a currency. |
| `clsExchangeCurrencyMenuScreen.h` | A menu screen for **Currency Exchange** operations. |
| `clsShowEchangeCurrencyScreen.h` | Handles the **currency exchange** process between accounts/currencies. |
| `clsInputValidate.h` | Class dedicated to **input validation** functions. |
| `clsLoginRegister.h` | Class for logging and displaying **user login attempts/history**. |

### ⚙️ Main and Data Files

| File Name | Description |
| :--- | :--- |
| `NewBankProject.cpp` | The **main execution file** containing the `main()` function, which initializes the application and calls the `clsLoginScreen` or `clsMainScreen`. |
| `clsScreen.cpp` | Implementation file for the base screen class. |
| `clsString.cpp` | Implementation file for the string utility class. |
| `Global.h` | A header file containing **global variables** or constants used across the entire project (e.g., currently logged-in user object). |
| `Clients.txt` | **Persistent data file** storing all bank client records. |
| `Users.txt` | **Persistent data file** storing all system user records. |
| `Currencies.txt` | **Persistent data file** storing currency details and exchange rates. |
| `TransferHistory.txt` | **Persistent data file** storing the log of all transfer transactions. |
| `LoginRegister.txt` | **Persistent data file** storing the log of user login attempts. |
| `.gitignore` | Specifies files and folders to be **ignored** by Git (e.g., compiled binaries, user-specific files). |
| `x64/Debug` | Directory containing the **compiled output** files for the debug build. |
| `clsUtility.vcxproj` | **Visual Studio Project file** for the utility library/project. |
| `clsUtility.vcxproj.filters` | Visual Studio file for managing the **logical grouping** of files in the Solution Explorer. |

---

## 🛠️ Requirements

* **C++ Compiler:** Requires a C++ compiler (e.g., GCC, Clang, MSVC) that supports modern C++ standards (C++11 or later is recommended).
* **IDE:** Visual Studio or any C++-compatible IDE is recommended for development and compilation.

---

## 🚀 Getting Started

1.  **Clone the repository:**
    ```bash
    git clone [Your Repository URL]
    ```
2.  **Open the project:**
    * Open `clsUtility.vcxproj` in Visual Studio.
3.  **Build and Run:**
    * Compile the project.
    * Run the compiled executable.
    * The application will start with the **Login Screen**.

---

## 🤝 Contributing

(Add details on how others can contribute, if applicable)

