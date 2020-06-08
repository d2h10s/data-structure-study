using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph_Algorithm
{
    class Node<T>
    {
        public List<Node<T>> neighbors = new List<Node<T>>();
        private List<int> weight;
        public T Data { get; set; }
        public Node() { }
        public Node(T value)
        {
            Data = value;
        }
        public List<int> Weight
        {
            get
            {
                weight = weight ?? new List<int>();
                return weight;
            }
        }
    }
}
