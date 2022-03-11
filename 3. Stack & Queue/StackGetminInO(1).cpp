
// Question - you are given with a stack , you have to write gitMin() function to return min element 
//            maintaining all the operations in O(1).

// Logic - we will keep track to minimum element using a variable , and update it while pushing 
//         new and poping new element.
//         push() -> if new element is less than previous minElement than we will push 2*x - minElement
//         pop() -> now if the element we are poping is less than minElement that means we have to get previous min,
//                  previous min = 2*minElement - x , x is top of stack.

class Stack {
    stack<int> S;
    int minElement;
    public:
        void push(int x) {
            if(S.empty()) {
                minElement = x;
                S.push(x);
            }
            else if(x < minElement) {
                S.push(2*x - minElement);
                minElement = x;
            }
            else {
                S.push(x);
            }
        }

        int pop() {
            if(S.top() < minElement) {
                minElement = 2*minElemnt - S.top();
            }
            S.pop();
            
        }

        int getMin() {
            return minElement;
        }

        int top() {
            return S.top();
        }

        int empty() {
            return S.empty();
        }
};