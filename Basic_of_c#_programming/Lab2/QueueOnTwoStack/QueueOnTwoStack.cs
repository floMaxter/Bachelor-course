using System;
using System.Collections;

namespace QueueOnTwoStack
{
    class QueueOnTwoStack
    {
        private Stack s1 = new Stack();
        private Stack s2 = new Stack();

        public void enQueue(int inputValue)
        {
            while (s1.Count > 0)
            {
                s2.Push(s1.Pop());
            }
            s1.Push(inputValue);
            while (s2.Count > 0)
            {
                s1.Push(s2.Pop());
            }
        }

        public int deQueue()
        {
            if(s1.Count == 0) {
                throw new Exception("Queue is emty");
            }
            int outputValue = (int)s1.Peek();
            s1.Pop();

            return outputValue;
        }
    }
}
