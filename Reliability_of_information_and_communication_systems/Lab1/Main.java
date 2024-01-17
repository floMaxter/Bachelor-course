import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter start and finis nodes: ");
        int s = sc.nextInt();
        int f = sc.nextInt();

        List<Edge> edgeList = initGraph();
        int numOfNode = countNodes(edgeList);
        Graph graph = new Graph(numOfNode, edgeList);

        Calculator pc = new Calculator(graph);
        pc.printTheoryProbability();
        pc.printPracticeProbability(s, f);
    }

    public static int countNodes(List<Edge> edgeList) {
        HashSet<Integer> hashSetNodes = new HashSet<>();
        for (Edge edge : edgeList) {
            hashSetNodes.add(edge.getFirstNode());
            hashSetNodes.add(edge.getSecondNode());
        }
        return hashSetNodes.size();
    }

    public static List<Edge> initGraph() {
        List<Edge> res = new ArrayList<>();
        res.add(new Edge(1, 2));
        res.add(new Edge(1, 3));
        res.add(new Edge(1, 4));
        res.add(new Edge(2, 4));
        res.add(new Edge(3, 4));
        res.add(new Edge(3, 5));
        res.add(new Edge(4, 5));
        res.add(new Edge(5, 6));
        res.add(new Edge(5, 7));
        res.add(new Edge(6, 7));
        res.add(new Edge(6, 8));
        res.add(new Edge(6, 9));
        res.add(new Edge(7, 9));
        res.add(new Edge(8, 9));

        /*res.add(new Edge(1, 2));
        res.add(new Edge(1, 3));
        res.add(new Edge(2, 3));*/
        return res;
    }
}

import java.util.List;

public class Graph {
    private final int numOfNode;
    private final List<Edge> edgeList;

    public Graph(int numOfNode, List<Edge> edgeList) {
        this.numOfNode = numOfNode;
        this.edgeList = edgeList;
    }

    public int getNumOfNode() {
        return numOfNode;
    }

    public List<Edge> getEdgeList() {
        return edgeList;
    }
}



import java.util.ArrayList;
import java.util.List;

public class Calculator {
    private final Graph graph;
    private final List<Integer> numOfOnes;
    private final List<Integer> subgraph;

    public Calculator(Graph graph) {
        this.graph = graph;
        this.numOfOnes = new ArrayList<>();
        this.subgraph = new ArrayList<>();
        initSubgraph();
    }

    private void initSubgraph() {
        for(int i = 0; i < graph.getEdgeList().size(); i++) {
            this.subgraph.add(0);
        }
    }

    public void printTheoryProbability() {
        System.out.println("Theoretical: ");
        for (double p = 0; p < 1; p += 0.1) {
            System.out.println("p = " + (float) p + ", path probability = " + (float) Math.pow(theoreticalProbability(p), 2));
        }
    }

    private static double theoreticalProbability(double p) {
        double halfGraph = -2 * Math.pow(p, 7) + 6 * Math.pow(p, 6) - 3 * Math.pow(p, 5) -
                            5 * Math.pow(p, 4) + 3 * Math.pow(p, 3) + 2 * Math.pow(p, 2);
        return halfGraph;
    }

    public void printPracticeProbability(int s, int f) {
        findCorrectSubgraph(s, f);

        System.out.println("Practice: ");
        for (double p = 0; p < 1.0; p += 0.1) {
            System.out.println("p = " + (float) p + ", path probability = " + (float) practiceProbability(p));
        }
    }

    private double practiceProbability(double p) {
        double res = 0;
        for (Integer one : numOfOnes) {
            res += Math.pow(p, one) * Math.pow((1 - p), graph.getEdgeList().size() - one);
        }
        return res;
    }

    private void findCorrectSubgraph(int s, int f) {
        do {
            BFS bfs = new BFS(graph.getNumOfNode());
            int ones = 0;
            for (int i = 0; i < subgraph.size(); i++) {
                if (subgraph.get(i) == 1) {
                    ones++;
                    int firstNode = graph.getEdgeList().get(i).getFirstNode();
                    int secondNode = graph.getEdgeList().get(i).getSecondNode();
                    bfs.addEdge(firstNode, secondNode);
                    bfs.addEdge(secondNode, firstNode);
                }
            }

            if (bfs.isPath(s - 1, f - 1)) {
                numOfOnes.add(ones);
            }
        } while (canIncrease());
    }

    private boolean canIncrease() {
        for (int i = 0; i < subgraph.size(); i++) {
            if (subgraph.get(i) == 0) {
                subgraph.set(i, 1);
                return true;
            } else {
                subgraph.set(i, 0);
            }
        }
        return false;
    }
}

public class Edge {
    private int firstNode;
    private int secondNode;

    public Edge(int firstNode, int secondNode) {
        this.firstNode = firstNode;
        this.secondNode = secondNode;
    }

    public int getFirstNode() {
        return firstNode;
    }

    public void setFirstNode(int firstNode) {
        this.firstNode = firstNode;
    }

    public int getSecondNode() {
        return secondNode;
    }

    public void setSecondNode(int secondNode) {
        this.secondNode = secondNode;
    }
}

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class BFS {
    private final int numOfNode;
    private final List<List<Integer>> adj;
    private final Queue<Integer> queue;

    public BFS(int numOfNode) {
        this.numOfNode = numOfNode;
        this.queue = new LinkedList<>();
        this.adj = new LinkedList<>();
        for(int i = 0; i < numOfNode; i++) {
            adj.add(new LinkedList<>());
        }
    }

    public void addEdge(int first, int second) {
        adj.get(first - 1).add(second - 1);
    }

    public boolean isPath(int s, int f) {
        return algoBFS(s, f);
    }

    private boolean algoBFS(int s, int f) {
        boolean[] visited = new boolean[numOfNode];

        visited[s] = true;
        queue.add(s);
        while(!queue.isEmpty()) {
            int currNode = queue.poll();

            for(int i = 0; i < adj.get(currNode).size(); i++) {
                int finish = (adj.get(currNode).get(i));
                if(finish == f) {
                    return true;
                } else if(!visited[finish]) {
                    visited[finish] = true;
                    queue.add(finish);
                }
            }
        }
        return false;
    }
}
