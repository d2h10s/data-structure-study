using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
    class Node<T>
    {
        public Node(T datum)
        {
            data = datum;
        }

        public T data { get; set; }

        public Node<T> next, prev;
    }
}
