#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Clear screen function
void clear_screen()
{
    system("cls");
}

// Account data node
struct Node
{
    int acc_number;
    char name[100];
    int amount;
    int password;
    struct Node *next;
};

// Loan data node
struct Loan
{
    int acc_number;
    char name[100];
    int loan_amount;
    int loan_balance;
    struct Loan *next;
};

// Feed back structure
struct feed_back
{
    char responce;
    struct feed_back *next;
};

// Head pointers of nodes
struct Node *head = NULL;
struct Loan *loan_head = NULL;
struct feed_back *feed_head = NULL;

// Function prototypes
void add_account();
void display_data();
void deposit();
void withdraw();
void transfer();
int acc_index(int acc, int pass);
int acc_check(int acc);
void delete_account();
void edit_account();
void display_main();
void save_data();
void load_data();
void save_loan_data();
void load_loan_data();
void atm();
void display_above_below();
void display_accounts_above_amount();
void display_accounts_below_amount();
void about_us();
void apply_loan();
void display_loan_data();
void feedback();
void load_feedback();
void save_feedback();
void feed_back_display();

int main()
{
    // Load data from file
    load_data();
    load_loan_data();
    load_feedback();

    while (1)
    {
        int option;

        // Display the main menu
        display_main();

        scanf("%d", &option);

        // Different functions call
        switch (option)
        {

        case 1:
            add_account();
            break;

        case 2:
            display_data();
            break;

        case 3:
            atm();
            break;

        case 4:
            edit_account();
            break;

        case 5:
            delete_account();
            break;

        case 6:
            display_above_below();
            break;

        case 7:
            apply_loan();
            break;

        case 8:
            display_loan_data();
            break;

        case 9:
            about_us();
            break;
        case 10:
            feed_back_display();
            break;

        case 11:
            // Save data to file
            feedback();
            save_data();
            save_loan_data();
            save_feedback();
            return 0;

        default:
            // for any invalid input
            printf("Invalid option!\n");
            printf("Please Input Valid option!!!\n");
            getch();
            break;
        }
    }
}

// Function to add feed back
void feedback()
{
    clear_screen();

    printf("Please enter your feedback:\n");
    printf("1. Good\n");
    printf("2. Average\n");
    printf("3. Bad needs improvement\n");
    printf("4. No Thanks (Exit)\n");

    int option;
    char response;
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        response = 'G';
        break;

    case 2:
        response = 'A';
        break;

    case 3:
        response = 'B';
        break;

    case 4:
        return;

    default:
        printf("Invalid option!\n");
        getch();
        return;
    }

    struct feed_back *newNode = (struct feed_back *)malloc(sizeof(struct feed_back));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        getch();
        return;
    }

    newNode->responce = response;
    newNode->next = feed_head;
    feed_head = newNode;

    printf("Feedback recorded successfully!\n");
    getch();
}

// Function to display the feedback responce
void feed_back_display()
{
    int good = 0, average = 0, bad = 0;
    struct feed_back *current = feed_head;

    while (current != NULL)
    {
        if (current->responce == 'G')
        {
            good++;
        }
        else if (current->responce == 'A')
        {
            average++;
        }
        else if (current->responce == 'B')
        {
            bad++;
        }
        current = current->next;
    }

    printf("---------------------------------------------------------------------\n");
    printf("Good response of the Bank management system:  %d\n", good);
    printf("Average response of the Bank management system:  %d\n", average);
    printf("Bad response of the Bank management system:  %d\n", bad);
    printf("---------------------------------------------------------------------\n");
    getch();
}

// Function to display the main menu
void display_main()
{
    // Clear the screen before displaying the main menu
    clear_screen();

    // Different functions choices
    printf("---------------------------------------------------------------------\n");
    printf("--                Bank Management System                           --\n");
    printf("---------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------\n");
    printf("---          1.Add account                                        ---\n");
    printf("---          2.Display account data                               ---\n");
    printf("---          3.ATM                                                ---\n");
    printf("---          4.Edit account detail                                ---\n");
    printf("---          5.Delete account                                     ---\n");
    printf("---          6.Display accounts above or below a certain amount   ---\n");
    printf("---          7.Apply for Loan                                     ---\n");
    printf("---          8.Display loan data                                  ---\n");
    printf("---          9.About us                                           ---\n");
    printf("---          10.Feed back display                                 ---\n");
    printf("---          11.Exit                                              ---\n");
    printf("---------------------------------------------------------------------\n");

    printf("Enter any option: ");
}

int acc_check(int acc)
{
    struct Node *current = head;
    int index = -1;
    while (current != NULL)
    {
        index++;
        if (current->acc_number == acc)
        {
            return index;
        }
        current = current->next;
    }
    return -1;
}

// Finding the index of account number
int acc_index(int acc, int pass)
{
    struct Node *current = head;
    int index = -1;
    while (current != NULL)
    {
        index++;
        if (current->acc_number == acc && current->password == pass)
        {
            return index;
        }
        current = current->next;
    }
    return -1;
}

// Adding account to the bank
void add_account()
{
    // Clear the screen before adding an account
    clear_screen();

    printf("Welcome to New Bank circuit.\n");

    int num;
    printf("Enter account number: ");
    scanf("%d", &num);

    if (acc_check(num) != -1)
    {
        printf("Account with this account number already exists.\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    // Adding adding in link list
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->acc_number = num;

    printf("Enter Password: ");
    scanf("%d", &newNode->password);
    printf("Enter Name of holder: ");
    scanf("%s", newNode->name);
    printf("Enter Amount: ");
    scanf("%d", &newNode->amount);

    newNode->next = head;
    head = newNode;
}

// ATM services of the Bank for 3 functions deposit , withdraw,transfer
void atm()
{
    // Clear the screen before displaying ATM options
    clear_screen();

    // Differnt fuction in atm option
    int option;
    printf("Select a field to edit:\n");
    printf("-------------------------------------------------------------------\n");
    printf("---      1.Deposit                             ---\n");
    printf("---      2.Withdraw                            ---\n");
    printf("---      3.Transfer                            ---\n");
    printf("---      4.Exit                                ---\n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        deposit();
        atm();
        break;

    case 2:
        withdraw();
        atm();
        break;

    case 3:
        transfer();
        atm();
        break;

    case 4:
        break;

    default:
        printf("Invalid option!\n");
        printf("Please enter valid input\n");
        getch();
        break;
    }
}

// Depositing money to the account
void deposit()
{
    // finding index of the account to Diposit
    int acc, pass, amo;
    printf("Enter account number: ");
    scanf("%d", &acc);
    printf("Enter password: ");
    scanf("%d", &pass);

    int index = acc_index(acc, pass);

    if (index == -1)
    {
        printf("Account does not exist or password is incorrect!!!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    // Entering Amount to deposit
    printf("Enter amount to deposit: ");
    scanf("%d", &amo);

    struct Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    current->amount += amo;
    printf("Amount Diposited successfully.\n");
    printf("Final Amount in account: %d", current->amount);
    getch();
}

// Withdrawing money from account
void withdraw()
{
    // finding index of the account to withdraw
    int acc, pass, amo;
    printf("Enter account number: ");
    scanf("%d", &acc);
    printf("Enter password: ");
    scanf("%d", &pass);

    int index = acc_index(acc, pass);
    if (index == -1)
    {
        printf("Account does not exist or password is incorrect!!!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    // Entering amount to withdraw
    printf("Enter amount to withdraw: ");
    scanf("%d", &amo);

    struct Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    if (amo > current->amount)
    {
        printf("Not enough balance.\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    else
    {
        current->amount -= amo;
        printf("Amount withdrawn successfully.\n");
        printf("Final Amount in account: %d", current->amount);
        getch();
    }
}

// Transfering money from one to other account
void transfer()
{
    int from_acc, to_acc, from_pass;
    int amount_transfer;

    // finding index of the account of user to transfer money
    printf("Enter Account number from: ");
    scanf("%d", &from_acc);
    printf("Enter Account password from: ");
    scanf("%d", &from_pass);

    int from_index = acc_index(from_acc, from_pass);
    if (from_index == -1)
    {
        printf("Sender account does not exist or password is incorrect!!!\n");
        printf("Please contact your Bank Customer Services\n");
        getch();
        return;
    }

    struct Node *from_node = head;
    for (int i = 0; i < from_index; i++)
    {
        from_node = from_node->next;
    }

    // finding index of the recipient account
    printf("Enter Account number to transfer money to: ");
    scanf("%d", &to_acc);

    int to_index = acc_check(to_acc);
    if (to_index == -1)
    {
        printf("Recipient account does not exist!!!\n");
        printf("Please contact your Bank Customer Services\n");
        getch();
        return;
    }

    if (from_acc == to_acc)
    {
        printf("Sender and recipient accounts cannot be the same!!!\n");
        printf("Please enter different accounts\n");
        getch();
        return;
    }

    struct Node *to_node = head;
    for (int i = 0; i < to_index; i++)
    {
        to_node = to_node->next;
    }

    // Entering transferring amount
    printf("Enter amount to transfer: ");
    scanf("%d", &amount_transfer);

    if (amount_transfer > from_node->amount)
    {
        printf("Not enough balance in the sender's account.\n");
        printf("Please contact your Bank Customer Services\n");
        getch();
        return;
    }

    // Transfer data process
    from_node->amount -= amount_transfer;

    to_node->amount += amount_transfer;

    printf("---------------------------------------------------------------------\n");
    printf("Amount transferred successfully.\n");
    printf("-------------------------------------------------------------------\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("Final Amount in sender account number %d and name  %s  \n", from_node->acc_number, from_node->name);
    printf("Final Amount in sender account: %d\n", from_node->amount);
    printf("---------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n\n");
    printf("Final Amount in recipient account number %d and name  %s \n", to_node->acc_number, to_node->name);
    printf("Final Amount in recipient account: %d \n", to_node->amount);
    printf("--------------------------------------------------------------------\n");
    getch();
}

// Displaying a particular record
void display_data()
{
    // Clear the screen before displaying account data
    clear_screen();
    int option;

    // Asking for choice of display
    printf("Select a field to edit:\n");
    printf("-------------------------------------------------------------------\n");
    printf("---      1.Personal data                            ---\n");
    printf("---      2.All data display                         ---\n");
    printf("---      3.Exit                                     ---\n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d", &option);

    struct Node *current = head;

    // Personal Data display
    if (option == 1)
    {
        int acc, pass, amo;
        printf("Enter account number: ");
        scanf("%d", &acc);
        printf("Enter password: ");
        scanf("%d", &pass);

        int index = acc_index(acc, pass);
        if (index == -1)
        {
            printf("Account does not exist or password is incorrect!!!\n");
            printf("Please contact to your Bank Customer Services\n");
            getch();
            return;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            printf("-------------------------------------\n");
            printf("Account Number: %d\n", current->acc_number);
            printf("Name: %s\n", current->name);
            printf("Amount: %d\n", current->amount);
            printf("-------------------------------------\n");
            getch();
        }
        display_data();
    }

    // All accouunts Data Display
    if (option == 2)
    {
        printf("Account details:\n");
        if (current == NULL)
        {
            printf("NO account Exist!!!");
            printf("Please contact to your Bank Customer Services\n");
            getch();
        }

        else
        {
            while (current != NULL)
            {
                printf("-------------------------------------\n");
                printf("Account Number: %d\n", current->acc_number);
                printf("Name: %s\n", current->name);
                printf("Amount: %d\n", current->amount);
                printf("-------------------------------------\n");
                current = current->next;
            }
            getch();
            display_data();
        }
    }

    // Exit option not perform anything
    if (option == 3)
    {
        return;
    };
}

// Deleting the account
void delete_account()
{
    // finding index of the account to delete
    int acc, pass;
    printf("Enter account to be deleted: ");
    scanf("%d", &acc);
    printf("Enter password of account: ");
    scanf("%d", &pass);

    int index = acc_index(acc, pass);
    if (index == -1)
    {
        printf("Account does not exist or password is incorrect!!!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    // Link list process to delete a account in a node
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL && current->acc_number != acc)
    {
        prev = current;
        current = current->next;
    }

    int val = current->amount;
    if (prev == NULL)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);

    printf("-------------------------------------------------------------------\n");
    printf("Account Deleted successfully with account number %d.\n", acc);
    printf("Amount in the account was %d \n", val);
    printf("-------------------------------------------------------------------\n");
    getch();

    // For deleting of loan account if present
    struct Loan *current_loan = loan_head;
    int index_loan = -1;
    while (current_loan != NULL)
    {
        if (current_loan->acc_number == acc)
        {
            index_loan++;
        }
        current_loan = current_loan->next;
    }

    if (index_loan >= 0)
    {
        struct Loan *current_loan = loan_head;
        struct Loan *prev_loan = NULL;

        while (current_loan != NULL)
        {
            if (current_loan->acc_number == acc)
            {
                if (prev_loan == NULL)
                {
                    loan_head = current_loan->next;
                }
                else
                {
                    prev_loan->next = current_loan->next;
                }

                free(current_loan);
                printf("-------------------------------------------------------------------\n");
                printf("Loan Account also Deleted successfully with account number %d.\n", acc);
                printf("-------------------------------------------------------------------\n");
                getch();
                break;
            }
            prev_loan = current_loan;
            current_loan = current_loan->next;
        }
    }
}

// Editing information related to account
void edit_account()
{
    int acc, pass;
    printf("Enter account number: ");
    scanf("%d", &acc);
    printf("Enter password of account: ");
    scanf("%d", &pass);

    int index = acc_index(acc, pass);
    struct Node *current = head;
    struct Loan *current_loan = loan_head;
    if (index == -1)
    {
        printf("Account does not exist or password is incorrect!!!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    else
    {
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
    }

    int option;
    // Options to select from to edit
    printf("Select a field to edit:\n");
    printf("---      1.Edit Name                               ---\n");
    printf("---      2.Edit Password                           ---\n");
    printf("---      3.Exit                                    ---\n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d", &option);

    char name[100];
    int pas;
    switch (option)
    {
    case 1:

        printf("Enter New name to the account: \n");
        scanf("%s", name);
        strcpy(current->name, name);
        while (current_loan != NULL)
        {
            if (current_loan->acc_number == acc)
            {
                strcpy(current_loan->name, name);
            }
            current_loan = current_loan->next;
        }

        break;
    case 2:

        printf("Enter New password for the account: \n");
        scanf("%d", &pas);
        current->password = pas;
        break;
    default:
        printf("Invalid option!\n");
        printf("Please enter valid input\n");
        getch();
        break;
    }

    printf("Data updated successfully.\n");
    getch();
}

// Function to display account brelow a desired amount
void display_above_below()
{
    // Clear the screen before displaying account data
    clear_screen();
    int option;

    // Asking for choice of display
    printf("Select a field to edit:\n");
    printf("--------------------------------------------------------------------\n");
    printf("---      1.display account above a desired amount                ---\n");
    printf("---      2.display account below a desired amount                ---\n");
    printf("---      3.Exit                                                  ---\n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d", &option);

    switch (option)
    {

    case 1:
        display_accounts_above_amount();
        break;

    case 2:
        display_accounts_below_amount();
        break;

    case 3:
        return;
        break;

    default:
        // for any invalid input
        printf("Invalid option!\n");
        printf("Please Input Valid option!!!\n");
        getch();
        break;
    }
}

// Function to display account above a desired amount
void display_accounts_above_amount()
{
    // Clear the screen before displaying accounts
    clear_screen();

    int threshold;
    printf("Enter the amount threshold: ");
    scanf("%d", &threshold);

    struct Node *current = head;
    int found = 0;

    printf("Accounts with amount greater than %d:  \n", threshold);
    while (current != NULL)
    {
        if (current->amount > threshold)
        {
            printf("-------------------------------------\n");
            printf("-------------------------------------\n");
            printf("Account Number: %d\n", current->acc_number);
            printf("Name: %s\n", current->name);
            printf("Amount: %d\n", current->amount);
            printf("-------------------------------------\n");
            printf("-------------------------------------\n");
            found = 1;
        }
        current = current->next;
    }
    getch();

    if (found == 0)
    {
        printf("No accounts found with amount greater than %d.\n", threshold);
        printf("Please contact to your Bank Customer Services\n");
        getch();
    }
}

// Function to display account below a desired amount
void display_accounts_below_amount()
{
    // Clear the screen before displaying accounts
    clear_screen();

    int threshold;
    printf("Enter the amount threshold: ");
    scanf("%d", &threshold);

    struct Node *current = head;
    int found = 0;

    printf("Accounts with amount greater than %d:  \n", threshold);
    while (current != NULL)
    {
        if (current->amount < threshold)
        {
            printf("-------------------------------------\n");
            printf("-------------------------------------\n");
            printf("Account Number: %d\n", current->acc_number);
            printf("Name: %s\n", current->name);
            printf("Amount: %d\n", current->amount);
            printf("-------------------------------------\n");
            printf("-------------------------------------\n");
            found = 1;
        }
        current = current->next;
    }
    getch();

    if (found == 0)
    {
        printf("No accounts found with amount greater than %d.\n", threshold);
        printf("Please contact to your Bank Customer Services\n");
        getch();
    }
}

void about_us()
{
    printf("-----------------------------------------------------------------------------------\n");
    printf("--     This is a cs102 project on bank management system                         --\n");
    printf("--     This is a Project of project group 34(in group 1-10)                      --\n");
    printf("--     Member of this group are:                                                 --\n");
    printf("--     2301EE42 :- Mayank Manas                                                  --\n");
    printf("--     2301AI46 :- Kumar Anurag                                                  --\n");
    printf("--     2301CB59 :- Dinesh Guguloth                                               --\n");
    printf("--     2301CT35 :- Akashat Mishra                                                --\n");
    printf("--     2301CT36 :- Tanushree vikas Janbandhu                                     --\n");
    printf("--     2301CS73 :- Karnati Supriya                                               --\n");
    printf("--     2301CS79 :- Sanjay Dasu                                                   --\n");
    printf("--     2301EC48 :- Kalyan Adithya Eslavath                                       --\n");
    printf("--     All rights to the above project is under the project group34\n");
    printf("------------------------------------------------------------------------------------\n");
    getch();
}

// Function to provide loan service
void apply_loan()
{
    // Clear the screen before displaying loan options
    clear_screen();

    int acc, pass, loan_amount, total_amount;
    printf("Enter account number: ");
    scanf("%d", &acc);
    printf("Enter password: ");
    scanf("%d", &pass);

    int index = acc_index(acc, pass);
    if (index == -1)
    {
        printf("Account does not exist or password is incorrect!!!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    int count = 0;
    struct Loan *current_loan = loan_head;
    while (current_loan != NULL)
    {
        if (current_loan->acc_number == acc)
        {
            count++;
        }
        current_loan = current_loan->next;
    }

    if (count == 0)
    {
        struct Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        printf("Enter loan amount: ");
        scanf("%d", &loan_amount);

        if (loan_amount <= 0)
        {
            printf("Invalid loan amount!!!\n");
            printf("Please enter a valid amount\n");
            getch();
            return;
        }

        total_amount = current->amount + loan_amount;
        current->amount = total_amount;

        // Add loan to the loan list
        struct Loan *newLoan = (struct Loan *)malloc(sizeof(struct Loan));
        newLoan->acc_number = acc;
        newLoan->loan_amount = loan_amount;
        strcpy(newLoan->name, current->name);
        newLoan->loan_balance = loan_amount;

        newLoan->next = loan_head;
        loan_head = newLoan;

        printf("Loan of %d has been approved and credited to your account.\n", loan_amount);
        printf("Total amount in your account: %d\n", total_amount);
        getch();
    }
    else
    {
        printf("--------------------------------------------------------------------\n");
        printf("---     Loan account already present with this account number %d ----\n", acc);
        printf("---     Please contact the bank manager for this                ----\n");
        printf("--------------------------------------------------------------------\n");
        getch();
    }
}

// Function to display loan data for a specific or all accounts
void display_loan_data()
{
    // Clear the screen before displaying loan data
    clear_screen();

    int option;

    // Asking for choice of display
    printf("Select a field to display:\n");
    printf("-------------------------------------------------------------------\n");
    printf("---      1.Display loan data for a specific account             ---\n");
    printf("---      2.Display loan data for all accounts                    ---\n");
    printf("---      3.Exit                                                  ---\n");
    printf("-------------------------------------------------------------------\n");
    scanf("%d", &option);

    struct Loan *current = loan_head;

    switch (option)
    {
    case 1:
    {
        int acc;
        printf("Enter account number: ");
        scanf("%d", &acc);

        int found = 0;
        while (current != NULL)
        {
            if (current->acc_number == acc)
            {
                printf("-------------------------------------\n");
                printf("Account Number: %d\n", current->acc_number);
                printf("Name of loan  acouunt holder: %s\n", current->name);
                printf("Loan Amount: %d\n", current->loan_amount);
                printf("Loan Balance: %d\n", current->loan_balance);
                printf("-------------------------------------\n");
                found = 1;
                break;
            }
            current = current->next;
        }

        if (found == 0)
        {
            printf("No loan records found for account number %d.\n", acc);
            printf("Please contact to your Bank Customer Services\n");
            getch();
        }
        else
        {
            getch();
        }
        break;
    }

    case 2:
        printf("Loan details:\n");
        if (current == NULL)
        {
            printf("No loan records found!!!\n");
            printf("Please contact to your Bank Customer Services\n");
            getch();
        }
        else
        {
            while (current != NULL)
            {
                printf("-------------------------------------\n");
                printf("Account Number: %d\n", current->acc_number);
                printf("Name of loan  acouunt holder: %s\n", current->name);
                printf("Loan Amount: %d\n", current->loan_amount);
                printf("Loan Balance: %d\n", current->loan_balance);
                printf("-------------------------------------\n");
                current = current->next;
            }
            getch();
        }
        break;

    case 3:
        return;
        break;

    default:
        // for any invalid input
        printf("Invalid option!\n");
        printf("Please Input Valid option!!!\n");
        getch();
        break;
    }
}

// File Handling

// Saving the performed data in the file
void save_data()
{

    printf("--------------Take your receipt!!!------------------------\n");
    printf("-----Thank you for using Banking Management system!!!-----\n");
    printf("-----      Brought To by projects Group 34           -----\n");

    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    struct Node *current = head;
    while (current != NULL)
    {
        fprintf(file, "%d %s %d %d\n", current->acc_number, current->name, current->password, current->amount);
        current = current->next;
    }

    fclose(file);
}

// Loading the file data to the structure list
void load_data()
{
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist! Starting with an empty database.\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    while (!feof(file))
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (fscanf(file, "%d %s %d %d", &newNode->acc_number, newNode->name, &newNode->password, &newNode->amount) == 4)
        {
            newNode->next = head;
            head = newNode;
        }
    }

    fclose(file);
}

// Function to save loan data to file
void save_loan_data()
{
    FILE *file = fopen("loans.txt", "w");
    if (file == NULL)
    {
        printf("Error opening loan file!\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    struct Loan *current = loan_head;
    while (current != NULL)
    {
        fprintf(file, "%d  %s %d %d\n", current->acc_number, current->name, current->loan_amount, current->loan_balance);
        current = current->next;
    }

    fclose(file);
}

// Function to load loan data from file
void load_loan_data()
{
    FILE *file = fopen("loans.txt", "r");
    if (file == NULL)
    {
        printf("Loan file does not exist! Starting with an empty loan database.\n");
        printf("Please contact to your Bank Customer Services\n");
        getch();
        return;
    }

    while (!feof(file))
    {
        struct Loan *newLoan = (struct Loan *)malloc(sizeof(struct Loan));
        if (fscanf(file, "%d %s %d %d", &newLoan->acc_number, newLoan->name, &newLoan->loan_amount, &newLoan->loan_balance) == 4)
        {
            newLoan->next = loan_head;
            loan_head = newLoan;
        }
    }
    fclose(file);
}

// Function to save feedback data from file
void save_feedback()
{
    FILE *file = fopen("responce.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        printf("Please contact your Bank Customer Services\n");
        getch();
        return;
    }

    struct feed_back *current = feed_head;
    while (current != NULL)
    {
        fprintf(file, "%c\n", current->responce);
        current = current->next;
    }

    fclose(file);
}

// Function to load feedback data from file
void load_feedback()
{
    FILE *file = fopen("responce.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist! Starting with an empty feedback database.\n");
        printf("Please contact your Bank Customer Services\n");
        getch();
        return;
    }

    char response;
    while (fscanf(file, " %c", &response) == 1)
    {
        struct feed_back *newNode = (struct feed_back *)malloc(sizeof(struct feed_back));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            getch();
            fclose(file);
            return;
        }

        newNode->responce = response;
        newNode->next = feed_head;
        feed_head = newNode;
    }
    fclose(file);
}