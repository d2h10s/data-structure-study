using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Graph_Algorithm
{
    class Graph<T>
    {
        private List<Node<T>> NodeList;
        public Graph()
        {
            NodeList = new List<Node<T>>();
        }
        public Node<T> AddNode(T data)
        {
            Node<T> node = new Node<T>(data);
            NodeList.Add(node);
            return node;
        }
        public void AddEdge(Node<T> from, Node<T> to, bool oneway = true, int weight = 0)
        {
            from.neighbors.Add(to);
            from.Weight.Add(weight);
            if (!oneway)
            {
                to.neighbors.Add(from);
                to.Weight.Add(weight);
            }
        }
        public void kruscal()
        {
            
        }
        public void print()
        {
            foreach(Node<T> node in NodeList)
            {
                foreach(var n in node.neighbors)
                {
                    string str = node.Data + " - " + n.Data;
                    Console.WriteLine(str);
                }
            }
        }
    }
}