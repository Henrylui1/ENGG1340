# Staff Management System
Contributors:
ENGG1340 Group 42
- Chou Cheuk Yin UID: 3035569691
- Lui Pui Him UID: 3035574115
<br /><sub>*The trend graphs may show uneven workload distribution between us. This is because one of us compiled and uploaded all the files for easier debugging.*</sub><br /><sup>*Our workload is shared.*</sup>
## Problem Statement
This is a staff management system that can collect and manage the employees' information of a small business.
## Problem Setting
We assume that there are around 15 staffs in the business, but it wouldn't matter if there are more employees.
## Program Version
### For Windows
The only files you need is mainsystem.cpp and the two text files **employees.txt** and **attributes.txt**. Ignore everything else.<br />
mainsystem.cpp is the complete file of the whole program. Compile and use it and you will be fine.
### For Linux
You can use the method of Makefile.
Type and run the following command : 
```
make main
```
and then type and run the following command :
```
./main
```
If it doesn't work, please compile and use mainsystem.cpp like in Windows.
## Program Features
### 1. A Menu will be provided for users
The users can choose what function to run through a dedicated menu. Function 7 also has its own small menu.
### 2. List all Employees
Output the list of employees with a specific, clean format. Horizontally the order is ID, name, age, role and salary.
This listing format is the same for all functions(except 7).
List is sorted through entering order.
### 3. Create a new employee with employee's personal information
Personal information include: ID, name, age, role, and salary. 
The name is assumed to be at most 20 charaters (including space), and the role to be at most 30 characters (including space).
### 4. Search for an employee
Search employee(s) through ID, name, age or role of the employee(s). 
For name/role searching, only a keyword is needed. If the employee's name/role contains the keyword, his/her information will be shown. (Searching IT for role will have all staff with role containing "IT" listed, e.g. both "IT manager" and "IT trainee" will be listed.)
### 5. Fire an employee
By deleting the employee's information. A confirmation is available to ensure you do not make the wrong decision.
### 6. Edit the details of an existing employee
Search the employee's ID and you can edit his/her name, age, role, and/or salary.
### 7. Search for all employees with a salary higher than or lower than a user input
Search employee(s) through salary. 
Type the amount first and then specify if you want to search the amount higher or lower than that. 
### 8. Adding/Editing user-defined attributes
Two sub-functions are available: 1)adding and 2)editing/viewing.
#### 8.1 Adding a new custom attribute
Define a new custom attribute and then initialize the attribute for every staff. Type "/" to skip a particular staff.
The attribute name as well as all the elements representing each staff MUST be within one word.
(NO spaces, e.g. "YearsWorked" or "Years_Worked" is ok but "Years Worked" is NOT.)
#### 8.2 Editing/Viewing an existing custom attribute
A list of existing custom attributes will be shown. Pick one and a list of employees with their ID, name and the attribute will be shown.
You may then choose a staff to edit. The elements representing the staff MUST be within one word.
(e.g. for a custom Nickname attribute, "FatBoy" or "Fat_Boy" is ok but "Fat Boy" is NOT.)
### 9. Sort the information of the employees
Sort and list all empployees through name(alphabetical order), age or salary.
## Some Limitaions
1. The input must follow the format.<br /> e.g. you must not type anything other than whole numbers under "ID", "age", or "salary".<br />For "name" and "role", you can type spaces. For function 7 (custom attributes) , you **CANNOT**.
2. Function 7 is basically a separate system and you cannot show every custom attributes as well as pre-defined attributes at the same time. There are no sort/search functions for custom attributes.
3. Finish the whole function and **DO NOT** force quit the program. Otherwise some information may be lost.
## Remarks
1. **employees.txt** is the file to store the basic information of employees. DO NOT change its filename and ONLY change the file content through the program. There are some example employees in the file. Change them if you wish (through the program) .
2. **attributes.txt** is the file to store custom attributes. DO NOT change its filename and ONLY change the file content through the program. The file is empty at the beginning.

<sub><sup>~~We may make a upgraded verison to enable the system listed on limitations. Subscribe to make this possible :)~~</sup></sub>

