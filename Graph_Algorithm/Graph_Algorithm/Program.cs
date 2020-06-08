using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph_Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            Graph<int> g = new Graph<int>();
            List<Node> n = new List<Node>();
            for(int i = 10; i < 51; i +=10) n.Add(g.AddNode(i));
            g.AddEdge(n[0], n[1]);
            g.AddEdge(n[1], n[3]);
            g.AddEdge(n[2], n[3]);
            g.AddEdge(n[2], n[4]);
            g.print();
            Console.ReadKey();
        }
    }
}
