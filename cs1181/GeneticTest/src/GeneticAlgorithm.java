import java.util.*;
import java.io.*;

public class GeneticAlgorithm {
    public static ArrayList<Item> readData(String filename) throws FileNotFoundException {
        ArrayList<Item> items = new ArrayList<>();
        Scanner scanner = new Scanner(new File(filename));
        while (scanner.hasNextLine()) {
            String[] line = scanner.nextLine().split(",");
            String name = line[0].trim();
            double weight = Double.parseDouble(line[1].trim());
            int value = Integer.parseInt(line[2].trim());
            items.add(new Item(name, weight, value));
        }
        return items;
    }

    public static ArrayList<Chromosome> initializePopulation(ArrayList<Item> items, int populationSize) {
        ArrayList<Chromosome> population = new ArrayList<>();
        for (int i = 0; i < populationSize; i++) {
            population.add(new Chromosome(items));
        }
        return population;
    }

    public static void main(String[] args) throws FileNotFoundException {
        ArrayList<Item> items = readData("items.txt");
        ArrayList<Chromosome> population = initializePopulation(items, 10);

        for (int i = 0; i < 20; i++) {
            ArrayList<Chromosome> nextGeneration = new ArrayList<>();

            // Add individuals to the next generation
            for (Chromosome chromosome : population) {
                nextGeneration.add(chromosome);
            }

            // Perform crossover
            for (int j = 0; j < population.size() / 2; j++) {
                Chromosome parent1 = population.get(j);
                Chromosome parent2 = population.get(population.size() - j - 1);
                nextGeneration.add(parent1.crossover(parent2));
            }

            // Perform mutation
            for (Chromosome chromosome : nextGeneration) {
                chromosome.mutate();
            }

            // Sort the next generation by fitness
            Collections.sort(nextGeneration);

            // Select top 10 individuals for the next population
            population.clear();
            population.addAll(nextGeneration.subList(0, 10));
        }

        // Sort the final population by fitness
        Collections.sort(population);

        // Display the fittest individual
        System.out.println("Fittest individual:");
        System.out.println(population.get(0));
    }
}
