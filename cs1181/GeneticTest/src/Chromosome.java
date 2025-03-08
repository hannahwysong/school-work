import java.util.ArrayList;
import java.util.Random;

class Chromosome extends ArrayList<Item> implements Comparable<Chromosome> {
    private static Random rng = new Random();

    public Chromosome() {
    }

    public Chromosome(ArrayList<Item> items) {
        for (Item item : items) {
            this.add(new Item(item));
            this.get(this.size() - 1).setIncluded(rng.nextBoolean());
        }
    }

    public Chromosome crossover(Chromosome other) {
        Chromosome child = new Chromosome();
        for (int i = 0; i < this.size(); i++) {
            Item parentItem = rng.nextDouble() < 0.5 ? this.get(i) : other.get(i);
            child.add(new Item(parentItem));
        }
        return child;
    }

    public void mutate() {
        for (Item item : this) {
            if (rng.nextDouble() < 0.1) {
                item.setIncluded(!item.isIncluded());
            }
        }
    }

    public int getFitness() {
        double totalWeight = 0;
        int totalValue = 0;
        for (Item item : this) {
            if (item.isIncluded()) {
                totalWeight += item.getWeight();
                totalValue += item.getValue();
            }
        }
        return totalWeight > 10 ? 0 : totalValue;
    }

    @Override
    public int compareTo(Chromosome other) {
        return Integer.compare(other.getFitness(), this.getFitness());
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Item item : this) {
            if (item.isIncluded()) {
                sb.append(item.toString()).append("\n");
            }
        }
        sb.append("Fitness: ").append(getFitness());
        return sb.toString();
    }
}