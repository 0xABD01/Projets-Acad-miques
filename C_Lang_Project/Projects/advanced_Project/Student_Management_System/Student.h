#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char firstName[50];
  char lastName[50];
  int age;
  float note;
} etudiant;

void systeme(etudiant user[]);
bool existId(etudiant user[], int newId);
void getId(etudiant user[], int indice);
void getAge(etudiant user[], int indice);
void getNote(etudiant user[], int indice);
int addStudent(etudiant user[], int *size);
void displayOneStudent(etudiant user[], int indice);
void displayAllStudent(etudiant user[], int size);
int getIdToSearch();
void searchStudentById(etudiant user[], int size);
void updateStudentNoteById(etudiant user[], int size);
void calculateStudentsAverage(etudiant user[], int size);
void displayStudentNotesAboveValue(etudiant user[], int size);
void permutation(etudiant *user1, etudiant *user2);
void sortStudentById(etudiant user[], int size);
void findYoungestStudent(etudiant user[], int size);
void removeStudentById(etudiant user[], int *size);
void removeAllStudent(etudiant user[], int *size);