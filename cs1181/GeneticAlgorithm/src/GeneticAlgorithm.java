import java.util.*;
import java.io.*;

/**
 * 
 * 
 * @author Hannah Wysong
 */
public class GeneticAlgorithm {
    
    /**
     * Reads in a data file with the format of item label, item weight, and
     * item value. Creates and returns an arrayList of item objects.
     * 
     * @param fileName items.txt List of items 
     * @return arrayList of items from the file
     * @throws FileNotFoundException Creates an exception if file is not found
     */
    public static ArrayList<Item> readData(String fileName) throws FileNotFoundException {
        ArrayList<Item> items = new ArrayList<>();
        //creates a scanner for the file
        Scanner scnr = new Scanner(new File(fileName));
        while (scnr.hasNextLine()){
            //creates an array of the file split at the commas
            String[] line = scnr.nextLine().split(",");
            // isolates each element
            String name = line[0].trim();
            double weight = Double.parseDouble(line[1].trim());
            int value = Integer.parseInt(line[2].trim());
            // adds new object to arraylist
            items.add(new Item(name, weight, value));
        }
        // returns arraylist
        return items;
    }

    /**
     * Creates and returns an arrayList of populationSizeChromosome objects that
     * contain items, with their included field randomly set to true or false.
     * 
     * @param items
     * @param populationSize
     * @return
     */
    public static ArrayList<Chromosome> initializePopulation(ArrayList<Item> items, int populationSize) {
        ArrayList<Chromosome> population = new ArrayList<>();
        // creates population arrayList of chromosome objects
        for (int i = 0; i < populationSize; i++){
            population.add(new Chromosome(items));
        }
        return population;
    }

    /**
     * Reads the data about the items in a file called items.txt and 
     * 
     * @param args Command line arguments
     * @throws FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException {
        //creates an arraylist of items from file
        ArrayList<Item> items = readData("items.txt");
        //adds 10 items to an arrayList of chromosomes
        ArrayList<Chromosome> population = initializePopulation(items, 10);

        //runs the algorithm 20 different times
        for (int i = 0; i < 20; i++){
            //creates a new arrayList of chromosomes
            ArrayList<Chromosome> newPopulation = new ArrayList<>();
            // adds old population to new population
            for (Chromosome chromosome : population){
                newPopulation.add(chromosome);
            }
            // performs the crossover
            for (int j = 0; j < population.size() / 2; j++){
                Chromosome parent1 = population.get(j);
                Chromosome parent2 = population.get(population.size() - j - 1);
                newPopulation.add(parent1.crossover(parent2));
            }
            //performs the mutation
            for (Chromosome chromosome: newPopulation){
                chromosome.mutate();
            }
            //sorts new population by fitness using comparable
            Collections.sort(newPopulation);
            //clears the original population 
            population.clear();
            // creates a new population with best fit items
            population.addAll(newPopulation.subList(0,10));
            }

            //sorts the final population by fitness
            Collections.sort(population);
            //prints the fittest individual
            System.out.println("Fittest indivdual: " + population.get(0));
        }
        // not sure why algorithm isnt working 
        // returns populations full of 0 fitness
    }