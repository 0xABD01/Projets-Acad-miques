#include"Student.h"

// fonction to orgnize fonctions
void systeme(etudiant user[]) {
  int size = 0;
  int choice;
  do {
    printf("\033[2J\033[1;1H");
    printf(".................................welcomme in this "
           "program................................................\n");
    printf("1. Add a new student to the system :\n");
    printf("2. Display all student details :\n");
    printf("3. Search for a student by ID :\n");
    printf("4. Update Note of student by ID :\n");
    printf("5. Calculate and display the average note of all students :\n");
    printf("6. Display students with notes above a certain value :\n");
    printf("7. Sort students by ID :\n");
    printf("8. Find the youngest student :\n");
    printf("9. Remove students :\n");
    printf("0. Exit :\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\033[2J\033[1;1H");
    printf(".................................welcomme in this "
           "program................................................\n");
    switch (choice) {
    case 1:
      printf("Add a new student to the system :\n\n");
      size = addStudent(user, &size);
      break;
    case 2:
      printf("Display all student details :\n\n");
      displayAllStudent(user, size);
      break;
    case 3:
      printf("Search for a student by ID :\n\n");
      searchStudentById(user, size);
      break;
    case 4:
      printf("Update Note of student by ID :\n\n");
      updateStudentNoteById(user, size);
      break;
    case 5:
      printf("Calculate and display the average note of all students :\n\n");
      calculateStudentsAverage(user, size);
      break;
    case 6:
      printf("Display students with notes above a certain value :\n\n");
      displayStudentNotesAboveValue(user, size);
      break;
    case 7:
      printf("Sort students by ID :\n\n");
      sortStudentById(user, size);
      break;
    case 8:
      printf("Find the youngest student :\n\n");
      findYoungestStudent(user, size);
      break;
    case 9:
      if (size == 0) {
        printf("No student in the system\n");
        break;
      }
      do {
        printf("1. Remove a student by ID :\n");
        printf("2. Remove All students :\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\033[2J\033[1;1H");
        printf(".................................welcomme in this "
               "program................................................\n");
        switch (choice) {
        case 1:
          printf("Remove a student by ID :\n\n");
          removeStudentById(user, &size);
          break;
        case 2:
          printf("Remove All students :\n\n");
          removeAllStudent(user, &size);
          break;
        default:
          printf("Invalid choice Please try again.\n");
          break;
        }
      } while (choice != 1 && choice != 2);
      break;
    case 0:
      printf("Exiting...ng\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
    if (choice != 0)
      do {
        printf("\n............................................................."
               "..........................................................\n");
        printf("1. return to the menu :\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n............................................................."
               "..........................................................\n");
        switch (choice) {
        case 1:
          break;
        case 0:
          printf("Exiting...\n");
          break;
        default:
          printf("Invalid choice Please try again.\n");
          break;
        }
      } while (choice != 0 && choice != 1);
  } while (choice != 0);
}

// fonction to check if the id is already used
bool existId(etudiant user[], int indice) {
  for (int j = 0; j < indice; j++) {
    if (user[indice].id == user[j].id)
      return true;
  }
  return false;
}

// fonction to get Id of new user
void getId(etudiant user[], int indice) {
  do {
    printf("unique id :");
    scanf("%d", &user[indice].id);
    existId(user, indice);
  } while (existId(user, indice));
}

// Function to get Age of a new user
void getAge(etudiant user[], int indice) {
  do {
    printf("Age : ");
    scanf("%d", &user[indice].age);
  } while (user[indice].age <= 0);
}

// function to get note of a new user
void getNote(etudiant user[], int indice) {
  do {
    printf("Note : ");
    scanf("%f", &user[indice].note);
  } while (user[indice].note < 0 || user[indice].note > 100);
}

// Function to add a new student
int addStudent(etudiant user[], int *size) {
  printf("etudiant %d :\n", *size);
  getId(user, *size);
  getchar();
  printf("firstName : ");
  gets(user[*size].firstName);
  printf("lastName : ");
  gets(user[*size].lastName);
  getAge(user, *size);
  getNote(user, *size);
  return (*size) + 1;
}

// Function to display one student
void displayOneStudent(etudiant user[], int indice) {
  printf("\n.............................................\n");
  printf("Student %d :\n", indice);
  printf("=>Id : %d\n", user[indice].id);
  printf("=>FirstName : ");
  puts(user[indice].firstName);
  printf("=>LastName : ");
  puts(user[indice].lastName);
  printf("=>Age : %d\n", user[indice].age);
  printf("=>Note : %.2f\n", user[indice].note);
}

// Function to display all student
void displayAllStudent(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  for (int i = 0; i < size; i++) {
    displayOneStudent(user, i);
  }
}

// Function to get id to search
int getIdToSearch() {
  int id;
  printf("Enter the id :");
  scanf("%d", &id);
  return id;
} // return id to search

// Function to search student by id
void searchStudentById(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  int id = getIdToSearch();
  for (int i = 0; i < size; i++) {
    if (user[i].id == id) {
      displayOneStudent(user, i);
      return;
    }
  }
  printf("thid id not found\n");
}

// Function to update note of student by id
void updateStudentNoteById(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  int id = getIdToSearch();
  for (int i = 0; i < size; i++) {
    if (user[i].id == id) {
      printf("Enter new ");
      getNote(user, i);
      displayOneStudent(user, i);
      return;
    }
  }
  printf("thid id not found\n");
}

// Function to calculate the average of students
void calculateStudentsAverage(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += user[i].note;
  }
  printf("the average is :%.2f", sum / size);
}

// Function to display student note above a value
void displayStudentNotesAboveValue(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  float value;
  printf("Enter the Note :");
  scanf("%f", &value);
  if (value < 0 || value > 100) {
    printf("invalide value is out of range\n");
    return;
  }
  int conteur = 0;
  for (int i = 0; i < size; i++) {
    if (user[i].note >= value) {
      displayOneStudent(user, i);
      conteur++;
      printf("\n");
    }
  }
  if (conteur == 0)
    printf("there is No student above this value :\n");
}

// Function permute 2 student
void permutation(etudiant *user1, etudiant *user2) {
  etudiant temp;
  temp = *user1;
  *user1 = *user2;
  *user2 = temp;
}

// Function to sort student by id
void sortStudentById(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (user[i].id > user[j].id) {
        permutation(&user[i], &user[j]);
      }
    }
  }
  printf("the students are now sorted\n");
}

// Function to find youngest student
void findYoungestStudent(etudiant user[], int size) {
  if (size == 0) {
    printf("No student in the system\n");
    return;
  }
  int indiceOfyonger = 0;
  for (int i = 1; i < size; i++) {
    if (user[i].age < user[indiceOfyonger].age)
      indiceOfyonger = i;
  }
  displayOneStudent(user, indiceOfyonger);
}

// Function to remove student by id
void removeStudentById(etudiant user[], int *size) {
  int id = getIdToSearch();
  for (int indice = 0; indice < *size; indice++) {
    if (user[indice].id == id) {
      for (int i = indice; i < *size - 1; i++)
        user[i] = user[i + 1];
      *size = *size - 1;
      printf("the student was removed\n");
      return;
    }
  }
  printf("thid id not found\n");
}

// Function to remove All students
void removeAllStudent(etudiant user[], int *size) {
  *size = 0;
  printf("All student were removed\n");
}