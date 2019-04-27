# Staff Management System
## Problem Statement
This is a staff management system that can collect and manage the employees' information of a small business.
## Problem Setting
We assume that there are around 15 staffs in the business, but it wouldn't matter if there are more employees.
## Program Features
### 1. List all Employees
Output the list of employees with a specific, clean format. Horizontally the order is ID, name, age, role and salary.
This listing format is the same for all functions(except 7).
List is sorted through entering order.
### 2. Create a new employee with employee's personal information
Personal information include: ID, name, age, role, and salary. 
The name is assumed to be at most 20 charaters (including space), and the role to be at most 30 characters (including space).
### 3. Search for an employee
Search employee(s) through ID, name, age or role of the employee(s). 
For name/role searching, only a keyword is needed. If the employee's name/role contains the keyword, his/her information will be shown. (Searching IT for role will have all staff with role containing "IT" listed, e.g. both "IT manager" and "IT trainee" will be listed.)
### 4. Fire an employee
By deleting the employee's information. A confirmation is available to ensure you do not make the wrong decision.
### 5. Edit the details of an existing employee
Search the employee's ID and you can edit his/her name, age, role, and/or salary.
### 6. Search for all employees with a salary higher than or lower than a user input
Search employee(s) through salary. 
Type the amount first and then specify if you want to search the amount higher or lower than that. 
### 7. Adding/Editing user-defined attributes
Two sub-functions are available: 1)adding and 2)editing/viewing.
#### 7.1 Adding a new custom attribute
Define a new custom attribute and then initialize the attribute for every staff. Type "/" to skip a particular staff.
The attribute name as well as all the elements representing each staff MUST be within one word.
(NO spaces, e.g. "YearsWorked" or "Years_Worked" is ok but "Years Worked" is NOT.)
#### 7.2 Editing/Viewing an existing custom attribute
A list of existing custom attributes will be shown. Pick one and a list of employees with their ID, name and the attribute will be shown.
You may then choose a staff to edit. The elements representing the staff MUST be within one word.
(e.g. for a custom Nickname attribute, "FatBoy" or "Fat_Boy" is ok but "Fat Boy" is NOT.)
### 8. Sort the information of the employees
Sort and list all empployees through name(alphabetical order), age or salary.
### 9. A Menu will be provided for users
The users can choose what function to run through a dedicated menu. Function 7 also has its own small menu.
## Some Limitaions
1. The input must follow the format, e.g. you must not type enything other than whole numbers under "age".<br />For "name" and "role", you can type spaces but for function 7 (custom attributes) , you CANNOT.
2. Function 7 is basically a separate system and you cannot show every custom attributes as well as original attributes at the same time.
