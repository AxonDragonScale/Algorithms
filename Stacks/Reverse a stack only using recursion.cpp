
// https://www.geeksforgeeks.org/?p=6921
// You cant use any data structure to store stack elements

void insertAtBottom(stack<int> &s, int itemToInsert) {
	if(!s.empty()) {
		int temp = s.top();
		s.pop();
		insertAtBottom(s, itemToInsert);
		s.push(temp);
	} else {
		s.push(itemToInsert);
	}
}

void reverse(stack<int> &s) {
	if(!s.empty) {
		int temp = s.top();
		s.pop();
		reverse(s);
		insertAtBottom(s, temp);
	}
}