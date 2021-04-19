using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
    class Queue<T>
    {
        public Queue()
        {
            head = tail = null;
        }

        public void enqueueu(T datum)
        {
            if(size < 1)
            {
                head = tail = new Node<T>(datum);
            }
            else
            {
                Node<T> newNode = new Node<T>(datum);
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
            size++;
        }

        public void dequeue()
        {
            if (size < 1)
            {
                
                Console.WriteLine("there is no Nodes");
                return;
            }
            //T tmp = head.data;
            head = head.next;
            size--;
            if (size < 1) tail = head;
            else head.prev = null;
            //return tmp;
        }

        public override string ToString()
        {
            StringBuilder str = new StringBuilder();
            str.Append("Queue: [ ");
            cur = head;
            for (int i = 0; i < size; i++)
            {
                str.Append(cur.data);
                if (i < size - 1)
                {
                    str.Append(", ");
                    cur = cur.next;
                }
            }
            return str.Append(" ]").ToString();
        }

        public int size { get; private set; } = 0;
        private Node<T> head, tail, cur;
    }
}