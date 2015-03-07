enum State { Unvisited, Visited, Visiting };

class Node{
	list<Node*> adjacent;
	int data;
	State state;
public:
	Node(int da) : data(da) , state(Unvisited){};
	int get_data() { return data;};
	list<Node*>::iterator get_adjacent_begin() {return adjacent.begin();};
	list<Node*>::iterator get_adjacent_end() {return adjacent.end();};
	State get_state() {return state;};
	void set_state(State st){state = st;};
};


bool findIsRoute(Node *source,Node *target){
	if ((source == NULL) || (target == NULL))
		return false;
	queue<Node*> q;
	q.push(source);
	Node * cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		(*cur).set_state(Visiting);
		for (list<Node*>::iterator x=(*cur).get_adjacent_begin();x !=(*cur).get_adjacent_end();++x){
			if ((**x).get_state()==Unvisited){
				if (*x==target)
					return true;
				(**x).set_state(Visiting);
				q.push(*x);
			}
		}
		(*cur).set_state(Visited);
	}
	return (false);
}