using System;
using System.Collections.Generic;

class converter
{
    private Dictionary<string, List<string>> graph;
    private Dictionary<string, List<string>> reversedGraph;
    private List<string> stack;
    private HashSet<string> visitedNodes;
    private List<List<string>> components;

    public converter(){
        graph = new Dictionary<string, List<string>>();
        reversedGraph = new Dictionary<string, List<string>>();
        stack = new List<string>();
        visitedNodes = new HashSet<string>();
        components = new List<List<string>>();
    }
    
    public void AddEdge(string u, string v){
        if (!graph.ContainsKey(u)) graph[u] = new List<string>();
        graph[u].Add(v);
        if (!reversedGraph.ContainsKey(v)) reversedGraph[v] = new List<string>();
        reversedGraph[v].Add(u);
    }
    private void FillStack(string v)
    {
        visitedNodes.Add(v);
        if (reversedGraph.ContainsKey(v)) {
            foreach (string neighbor in reversedGraph[v]) {
                if (!visitedNodes.Contains(neighbor))
                    FillStack(neighbor);
            }
        }
        stack.Add(v);
    }
    private void DFS(string v, HashSet<string> visitedNodes, List<string> component){
        visitedNodes.Add(v);
        component.Add(v);
        if (graph.ContainsKey(v)) {
            foreach (string neighbor in graph[v]) {
                if (!visitedNodes.Contains(neighbor))
                    DFS(neighbor, visitedNodes, component);
            }
        }
    }

    public List<List<string>> GetComponents(){
        foreach (var v in reversedGraph.Keys) {
            if (!visitedNodes.Contains(v))
                FillStack(v);
        }
        visitedNodes.Clear();
        
        while (stack.Count > 0) {
            string v = stack[stack.Count - 1];
            stack.RemoveAt(stack.Count - 1);
            if (!visitedNodes.Contains(v))
            {
                List<string> component = new List<string>();
                DFS(v, visitedNodes, component);
                components.Add(component);
            }
        }
        return components;
    }
}

public static class Program
{
    public static List<List<string>> StartConverter(Dictionary<string, List<string>> graph){
        converter converter = new converter();
        foreach (var u in graph.Keys) {
            foreach (var v in graph[u]) {
                converter.AddEdge(u, v);
            }
        }
        return converter.GetComponents();
    }

    public static Dictionary<string, bool> CheckRecursiveCalls(List<List<string>> components, Dictionary<string, List<string>> graph){
        Dictionary<string, bool> recursiveCalls = new Dictionary<string, bool>();
        foreach (var component in components) {
            HashSet<string> visitedNodes = new HashSet<string>();
            foreach (var node in component) {
                if (!visitedNodes.Contains(node)) DFSRecCheck(node, visitedNodes, component);
            }
        }
        return recursiveCalls;
        
        void DFSRecCheck(string node, HashSet<string> visitedNodes, List<string> component)
        {
            visitedNodes.Add(node);
           if (graph.ContainsKey(node)) {
                foreach (string neighbor in graph[node]) {
                    if (component.Contains(neighbor)) {
                        recursiveCalls[node] = true;
                        break;
                    }
                    if (!visitedNodes.Contains(neighbor)) DFSRecCheck(neighbor, visitedNodes, component);
                }
            }
            if (!recursiveCalls.ContainsKey(node)) recursiveCalls[node] = false;
        }
    }

    public static void Main(string[] args){
        Dictionary<string, List<string>> graph = new Dictionary<string, List<string>> {
            { "foo", new List<string> { "bar", "baz", "qux" } },
            { "bar", new List<string> { "baz", "foo", "bar" } },
            { "qux", new List<string> { "qux" } },
            { "baz", new List<string>() }
        };
        List<List<string>> components = StartConverter(graph);
        List<string> largestComponent = components[0];
        foreach (var component in components) {
            if (component.Count > largestComponent.Count)
                largestComponent = component;
        }
        Console.WriteLine("Largest recursive component: " + string.Join(", ", largestComponent));
        Dictionary<string, bool> recursiveCalls = CheckRecursiveCalls(components, graph);
        Console.WriteLine("\nRecursive calls:");
        foreach (var function in recursiveCalls.Keys) {
            Console.WriteLine($"{function}: {(recursiveCalls[function] ? "True" : "False")}");
        }
    }
}
