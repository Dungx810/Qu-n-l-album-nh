#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int ID;
	char name[100];
	int year;
	char publisher[100];
	char topic[100];
} Book;

typedef struct Node {
	Book data;
	struct Node* next;
} Node;

Book createBook(int ID, const char* name, int year, const char* publisher, const char* topic) {
	Book book;
	book.ID = ID;
	strcpy_s(book.name, name);
	book.year = year;
	strcpy_s(book.publisher, publisher);
	strcpy_s(book.topic, topic);
    return book;
}

Node* initList() {
	return NULL;
}

Node* insertAtHead(Node *head, Book book) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Memory allocation failed!");
		return head;
	}
	newNode->data = book;
	newNode->next = head;
	return newNode;
}

Node* insertAtTail(Node* head, Book book) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = book;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// 6. Hàm chèn vào trước/sau một vị trí bất kỳ
Node* insertAtPosition(Node* head, Book book, int position, int before) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = book;

    if (position == 0 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    for (int i = 0; i < position - (before ? 1 : 0) && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (before) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// 7. Hàm tìm một cuốn sách theo tên
Node* findBookByName(Node* head, const char* name) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// 8. Hàm đếm số lượng sách trong danh sách
int countBooks(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 9. Hàm in ra màn hình các cuốn sách
void printBooks(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Year: %d, Publisher: %s, Topic: %s\n",
            temp->data.ID, temp->data.name, temp->data.year, temp->data.publisher, temp->data.topic);
        temp = temp->next;
    }
}

// Hàm main để thể hiện các hàm trên
int main() {
    Node* bookList = initList();  // 3. Khởi tạo danh sách

    // Thêm vài cuốn sách vào danh sách
    Book book1 = createBook(1, "Book 1", 2001, "Publisher 1", "Topic 1");
    Book book2 = createBook(2, "Book 2", 2002, "Publisher 2", "Topic 2");
    Book book3 = createBook(3, "Book 3", 2003, "Publisher 3", "Topic 3");

    // Chèn sách vào đầu, cuối và vị trí bất kỳ
    bookList = insertAtHead(bookList, book1);       // 4. Chèn vào đầu
    bookList = insertAtTail(bookList, book2);       // 5. Chèn vào cuối
    bookList = insertAtPosition(bookList, book3, 1, 0);  // 6. Chèn sau vị trí 1

    // 9. In danh sách sách
    printf("Danh sach sach:\n");
    printBooks(bookList);

    // 7. Tìm sách theo tên
    Node* foundBook = findBookByName(bookList, "Book 2");
    if (foundBook != NULL) {
        printf("\nTim thay sach: %s\n", foundBook->data.name);
    }
    else {
        printf("\nKhong tim thay sach! \n");
    }

    // 8. Đếm số sách trong danh sách
    printf("\nSo sach co trong danh sach: %d\n", countBooks(bookList));

    return 0;
}