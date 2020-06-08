using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    class LL<T>
    {
        private Node<T> head, tail, cur;
        public int size()
        {
            int size = 0;
            cur = head;
            for (size = 1; cur.next != null; size++) cur = cur.next;
            return size;
        }
        public void addFirst(T datum)
        {
            if(head == null)
            {
                head = tail = new Node<T>(datum);
            }
            else
            {
                Node<T> newNode = new Node<T>(datum);
                newNode.next = head;
                head = newNode;
            }
        }
        public void addLast(T datum)
        {
            cur = head;
            if(head == null)
            {
                head = tail = new Node<T>(datum);
                return;
            }
            Node<T> newNode = new Node<T>(datum);
            tail.next = newNode;
            tail = newNode;
        }
        public void addidx(int idx, T datum)
        {
            int size = this.size();
            if (idx >= size) return;
            cur = head;
            for (int i = 0; i < idx - 1; i++) cur = cur.next;
            Node<T> newNode = new Node<T>(datum);
            newNode.next = cur.next;
            cur.next = newNode;
        }
        public override string ToString()
        {
            StringBuilder str = new StringBuilder("LL: [ ");
            cur = head;
            while (cur != null)
            {
                str.Append(cur.Data);
                if (cur.next != null)
                {
                    str.Append(" ,");
                    cur = cur.next;
                }
                else break;
            }
            return str.Append(" ]").ToString();
        }
        public string Reverse()
        {
            StringBuilder ssb = new StringBuilder();
            cur = head;
            while (cur != null)
            {
                ssb.Append(cur.Data);
                if (cur.next != null)
                {
                    ssb.Append(", ");
                    cur = cur.next;
                }
                else break;
            }
            string ss = ssb.ToString();
            ssb.Clear();

            foreach(char c in ss.Reverse())
            {
                ssb.Append(c);
            }
            return "LL (Reverse): [ " + ssb.ToString() + " ]";
        }
    }
}
