#include<iostream>
using namespace std;
struct postfix{
	float data;
	postfix *nxt;
	int flag;
};
postfix*head = NULL;
void add(float value, int fg = 0){
	postfix *newnode = new postfix;
	newnode->data = value;
	newnode->flag = fg;
	newnode->nxt = NULL;
	if (head == NULL){
		head = newnode;
	}
	else{
		postfix *t1 = head;
		while (t1->nxt != NULL){
			t1 = t1->nxt;
		}
		t1->nxt = newnode;
	}

}
void delete_last(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		postfix* t = head, *d = t->nxt;
		if (t->nxt == NULL){
			head = head->nxt;
		}
		else{

			while (t->nxt->nxt != NULL){
				t = t->nxt;
				d = d->nxt;
			}

			t->nxt = NULL;
			delete(d);
		}
	}
}
void delete_value(float value){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{

		if (head->data == value){
			postfix*d = head;
			head = head->nxt;
			delete(d);
		}
		else{
			postfix* t = head, *d = t->nxt;
			while (t->nxt != NULL && t->nxt->data != value){
				t = t->nxt;
				d = d->nxt;
			}
			if (t->nxt == NULL){
				cout << value << " is not found" << endl;
			}
			else{
				t->nxt = t->nxt->nxt;
				d->nxt = NULL;
				delete(d);
			}

		}
	}

}
struct stack_node{
	char data;
	stack_node *next;
};
stack_node *top = NULL;
void push(char value){
	stack_node*newnode = new stack_node;
	newnode->data = value;
	newnode->next = NULL;
	if (top == NULL){
		top = newnode;
	}
	else{
		newnode->next = top;
		top = newnode;

	}
}
void pop(){
	if (top == NULL){
		cout << "list is empty" << endl;
	}
	else{
		stack_node*d = top;
		top = top->next;
		delete(d);
	}
}
int print(){
	if (head == NULL){
		cout << "list is empty" << endl;
	}
	else{
		cout << "the postfix expression of the infix expression is:" << endl;
		postfix *t = head;
		stack_node*s = top;
		while (s->data != 'x'){
			add(s->data, 1);
			s = s->next;
		}
		while (t != NULL){

			if (t->flag == 1)
				cout << char(t->data) << ",";
			else
				cout << t->data << ",";
			t = t->nxt;
		}

		cout << endl;
	}
	return 0;
}
void main(){
	int  i = 0;
	int fraction_point = 0;
	int after_fraction_point = 0;
	int	after_fraction_carrier = 0;
	int	int_couter = 0;
	int int_before_fraction = 0;
	int	neg_flag = 1;
	int flag_carrier_1 = 0;
	int	flag_carrier_f = 0;
	int input_counter = 0;
	char current_input;
	char previous_input = '\0';
	float value = 0;
	float value_carrier = 0;
	push('x');
start:
	for (i = 0; i < 100; i++){

		cin >> current_input;
		if ((previous_input == '+' || previous_input == '-' || previous_input == '*' || previous_input == '/') &&
			(current_input == '-' || current_input == '+' || current_input == '*' || current_input == '/')){
			cout << "wrong expression" << endl; goto thank;
		}
		previous_input = current_input;
		input_counter++;
		if (input_counter == 1 && (current_input == '-' || current_input == '+' || current_input == '*' || current_input == '/')){
			if (current_input == '-')
				neg_flag = -1;
			if (current_input == '*' || current_input == '/'){
				cout << "wrong expression" << endl; goto thank;
			}
			goto start;
		}
		if (current_input == '-' && (top->data == '(' || top->data == '{' || top->data == '[')){
			neg_flag = -1;
			goto start;
		}

		if (current_input == 'e'){
			break;
		}
		else{
			if ((current_input >= '0'&&current_input <= '9') || current_input == '.'){

				if (current_input == '.'){
					fraction_point = 1;
					goto start;
				}
				if (fraction_point == 1){
					after_fraction_point = after_fraction_point + 1;
					after_fraction_carrier = after_fraction_point;
					value = (int(current_input) - 48)*neg_flag;
					flag_carrier_f = neg_flag;
					neg_flag = 1;
					if (after_fraction_point > 1 || int_before_fraction == 1){
						delete_last();
					}
					int m = 1;
					while (after_fraction_carrier != 0){
						m = m * 10;
						after_fraction_carrier--;
					}
					if (int_before_fraction == 0 && flag_carrier_f == -1 && after_fraction_carrier == 1){
						value = value_carrier + value / m;
					}
					else{
						if (flag_carrier_1 == -1){


							value = value_carrier - value / m;

						}
						else{
							if (int_before_fraction == 0 && value_carrier < 0){
								value = value_carrier - value / m;
							}
							else
								value = value / m + value_carrier;
						}
					}
					value_carrier = value;
					add(value);
					i++;
					goto start;
				}
				else{
					int_couter = int_couter + 1;
					if (int_couter == 1){
						value = (int(current_input) - 48)*neg_flag;
						flag_carrier_1 = neg_flag;
						neg_flag = 1;
						value_carrier = value;
					}
					int m = 1;
					if (int_couter > 1){
						delete_last();
						value = (int(current_input) - 48);
						if (flag_carrier_1 == -1){
							value = value_carrier * 10 - value;
						}
						else
							value = value_carrier * 10 + value;
						value_carrier = value;
					}
					int_before_fraction = 1;
					add(value);
					i++;
					goto start;
				}
			}

			else{
				fraction_point = 0;
				after_fraction_point = 0;
				int_before_fraction = 0;
				int_couter = 0;
				value = 0;
				value_carrier = 0;
				neg_flag = 1;
				flag_carrier_1 = 1;
				flag_carrier_f = 1;

				if (current_input == '(' || current_input == '{' || current_input == '['){
					push(current_input);
					i++;
					goto start;
				}

				if (current_input == '+' || current_input == '-' || current_input == '*' || current_input == '/'){
					if (top->data == '+' || top->data == '-' || top->data == '*' || top->data == '/'){
						if ((current_input == '+' || current_input == '-') && (top->data == '+' || top->data == '-')){
							while (top->data == '+' || top->data == '-'){
								add(int(top->data), 1);
								pop();
							}
							push(current_input); goto start;
						}
						else if ((current_input == '+' || current_input == '-') && (top->data == '*' || top->data == '/')){
							while (top->data == '*' || top->data == '/' || top->data == '+' || top->data == '-'){
								add(int(top->data), 1);
								pop();
							}
							push(current_input); goto start;
						}
						else if ((current_input == '*' || current_input == '/') && (top->data == '+' || top->data == '-')){
							push(current_input);
							i++;
							goto start;
						}
						else if ((current_input == '*' || current_input == '/') && (top->data == '*' || top->data == '/')){
							while (top->data == '*' || top->data == '/' || top->data == '+' || top->data == '-'){
								add(int(top->data), 1);
								pop();
							}
							push(current_input); goto start;
						}
					}
					else {
						push(current_input);
						i++;
						goto start;
					}
				}
				else if (current_input == ')'){

					while (top->data != '('){
						if (top->data == 'x'){
							cout << "expression has an extra ')'" << endl; goto thank;
						}
						add(int(top->data), 1);
						pop();
					}
					pop();
					goto start;
				}
			}
		}
	}
	stack_node*t = top;
	while (t->next != NULL){
		if (t->data == '(')
		{
			cout << "expression has an extra opening bracket" << endl; goto thank;
		}
		t = t->next;
	}
	print();


result:
	postfix *p = head;

	if (p->nxt == NULL){
		cout << "Result is : " << p->data << endl; goto thank;
	}

	else{

		if ((p->nxt->flag == 1 && p->nxt->nxt == NULL)){
			cout << "invalid expression" << endl; goto thank;
		}
		else{
			while (p->nxt->nxt->flag != 1){

				p = p->nxt;
			}
		}

		if (p->nxt->nxt->data == int('+')){
			p->data = p->data + p->nxt->data;
			delete_value(p->nxt->data);
			delete_value(p->nxt->data);
			goto result;
		}
		if (p->nxt->nxt->data == int('-')){

			p->data = p->data - p->nxt->data;
			delete_value(p->nxt->data);
			delete_value(int('-'));
			goto result;
		}
		if (p->nxt->nxt->data == int('*')){
			p->data = p->data * p->nxt->data;
			delete_value(p->nxt->data);
			delete_value(p->nxt->data);
			goto result;
		}
		if (p->nxt->nxt->data == int('/')){
			p->data = p->data / p->nxt->data;
			delete_value(p->nxt->data);
			delete_value(int('/'));
			goto result;
		}
	}


thank:
	cout << "thank you" << endl;
}