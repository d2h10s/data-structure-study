using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph_Algorithm
{

    class Priority_Queue<T> where T: IComparable<T>
    {
        class Node
        {
            public Node(T datum, int prt)
            {
                data = datum;
                priority = prt;
            }

            public T data { get; set; }
            public int priority { get; set; }

            public Node next, prev;
        }

        public Priority_Queue()
        {
            head = tail = null;
        }

        public void enqueueu(T datum, int prt)
        {
            if (size < 1)
            {
                head = tail = new Node(datum, prt);
            }
            else
            {
                Node newNode = new Node(datum, prt);
                Node p = head;
                Node q = head.next;
                while(p.data <= q.data)
                {

                }
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
        private Node head, tail, cur;
    }
}