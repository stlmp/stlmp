#ifndef STACKMP_H
#define STACKMP_H

template<class T>
class stackmp
{
    struct node{
        node(T v, node* nxt){value = v; next = nxt;}
        T value;
        node* next;
    };
    
    public:
        stackmp(){
			tail = nullptr;
			sz = 0;
		}
        stackmp(T value, int intial_size){
			sz = intial_size;
			tail = nullptr;
			while(intial_size > 0)
			{
				node* temp = new node(value, tail);
				tail = temp;
				intial_size--;
			}
		}
        T& peek(){
			try{
				if(tail == nullptr)
					throw(0);
			}catch(...){
				std::cout << "EmptyStack" << std::endl;
			}
			return tail->value;
		}
        void pop(){
			sz--;
			if(tail == nullptr)
				return;
			node* temp = tail;
			tail = tail->next;
			delete temp;
		}
        void push(T value){
			node* temp = new node(value, tail);
			tail = temp;
			sz++;
		}
        int size(){
			return sz;
		}
        void print(){
			node* temp = tail;
			while(temp != nullptr)
			{
				std::cout << temp->value << " ";
				temp = temp->next;
			}
		}
        virtual ~stackmp(){
			node* temp = tail;
			while(temp != nullptr)
			{
				temp = tail;
				tail = tail->next;
				delete temp;
			}
		}
    private:
        node* tail;
        int sz;
};

#endif // STACKMP_H
