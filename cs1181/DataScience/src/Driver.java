import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Main class for Project 3. Creates both the train and truck events and runs
 * the simulation. Records statistics. 
 * 
 * @author Hannah Wysong
 */
public class Driver {
    //Constants
    static int TOTAL_PACKAGES = 1500;
    static int DIST_TO_TRAIN_CROSSING = 3000;
    static int DIST_AFTER_TRAIN_CROSSING = 27000;
    static int DRONE_SPEED = 500;
    static int DRONE_TAKE_OFF_DELAY = 3;

    static int TRUCK_SPEED = 30;
    static int TRUCK_CAPACITY = 10;
    static int TRUCK_TAKE_OFF_DELAY = 15;
    static float PRECENT_BY_DRONE = 0.25f;

    // finds num of drones and trucks
    static double NUM_DRONES = Math.ceil(TOTAL_PACKAGES * PRECENT_BY_DRONE);
    static int NUM_TRUCKS = (int)Math.ceil((TOTAL_PACKAGES - NUM_DRONES) / TRUCK_CAPACITY); 

    // creates queues
    static PriorityQueue<Event> pq = new PriorityQueue<Event>();
    static Queue<Double> startTimes = new LinkedList<Double>();

    private static double totalTruckTime = 0;

    /**
     * Main method of Driver class. Prints opening statistics and train schedule. Then runs the simulation
     * using events. After the simulation is finished, final statistics are printed.
     * 
     * @param args command line arguments
     * @throws Exception thrown if file is not found
     */
    public static void main(String[] args) throws Exception{

        // printing opening statistics
        System.out.println("With " + PRECENT_BY_DRONE * 100 + "% drones and " + TOTAL_PACKAGES + " packages,");
        System.out.println("There will be:");
        System.out.println("-" + (int)NUM_DRONES + " drones");
        System.out.println("-" + (NUM_TRUCKS - 1) + " trucks");
        System.out.println("");

        // prints train schedule
        truckStart();
        System.out.println("TRAIN SCHEDULE ");
        System.out.println("---------------");
        makeTrains("train_schedule.txt");

        Queue<Event> waitingTrucks = new LinkedList<Event>();
        boolean isTrain = false;


        // Start simulation
        System.out.println("");
        // iterates through priority queue until empty
        while (!pq.isEmpty()) {
            // polls first event in queue 
            Event e = pq.poll();
            if (e instanceof Truck_Start) {
                startTimes.add(e.getTime());
                // creates truck crossing event based on start time
                double crossingTime = (DIST_TO_TRAIN_CROSSING / TRUCK_SPEED) + e.getTime();
                Truck_At_Crossing truckAtCrossingEvent = new Truck_At_Crossing(crossingTime, e.getTruckNum());
                pq.add(truckAtCrossingEvent);
                // prints start event
                System.out.println(e.getTime() + ": TRUCK #" + e.getTruckNum() + " begins journey");
            } else if (e instanceof Truck_At_Crossing) {
                // if there is a train at crossing
                if (isTrain) {
                    // adds truck to waiting queue
                    waitingTrucks.add(e);
                    // prints truck at crossing event
                    System.out.println(e.getTime() + ": TRUCK #" +e.getTruckNum() + " waits at crossing");
                } else {
                    // if there is no train creates a truck crossing event
                    double crossingEndTime = e.getTime() + 1;
                    Truck_Crossing truckCrossingEvent = new Truck_Crossing(crossingEndTime, (int)e.getTruckNum());
                    pq.add(truckCrossingEvent);
                }
            } else if (e instanceof Truck_Crossing) {
                // creates an end event after truck crosses
                double endTime = (DIST_AFTER_TRAIN_CROSSING / TRUCK_SPEED) + e.getTime();
                Truck_End truckEndEvent = new Truck_End(endTime, (int)e.getTruckNum());
                pq.add(truckEndEvent);
                // prints crossing event
                System.out.println(e.getTime() + ": TRUCK #" + e.getTruckNum() + " crosses crossing");
            } else if (e instanceof Truck_End) {
                // records duration of trip when truck event ends
                double start = startTimes.poll();
                int totalTime = (int)(e.getTime() - start);
                totalTruckTime += totalTime;
                // prints truck end event
                System.out.println(e.getTime() + ": TRUCK #" + e.getTruckNum() + " ends journey");
            } else if (e instanceof Train_Start) {
                // adds train to crossing and prints event
                isTrain = true; 
                System.out.println(e.getTime() + ": TRAIN arrives at crossing");
            } else if (e instanceof Train_End) {
                // removes train from crossing and prints event
                System.out.println(e.getTime() + ": TRAIN crosses crossing");
                isTrain = false;
            }

            // prints final statistics
        }   System.out.println("");
            // rounds truck avg truck time
            double truckAvgTime = Math.ceil(totalTruckTime / NUM_TRUCKS);
            // finds drone time using distance and drone speed
            double droneTime = (DIST_TO_TRAIN_CROSSING + DIST_AFTER_TRAIN_CROSSING) / DRONE_SPEED;
            // uses drone delay and total drone number to find total time
            double totalDroneTime = (NUM_DRONES * DRONE_TAKE_OFF_DELAY) + droneTime - DRONE_TAKE_OFF_DELAY;
            
            System.out.println("TRUCK AVG TRIP TIME: " + truckAvgTime + " minutes");
            System.out.println("TRUCK TOTAL TIME: " + totalTruckTime + " minutes");
            System.out.println("");

            System.out.println("DRONE TRIP TIME: " + droneTime + " minutes");
            System.out.println("DRONE TOTAL TIME: " + totalDroneTime  + " minutes");
            System.out.println("");

            System.out.println("TOTAL TIME: " + (totalTruckTime + totalDroneTime));     
    }

    

    /**
     * Creates Truck events. Iterates through number of trucks and creates an event
     * containg the time and truck num. 
     */
    public static void truckStart() {
    
        for (int i = 0; i < NUM_TRUCKS; i++) {
            int startTime = i * TRUCK_TAKE_OFF_DELAY;
            Truck_Start truckStartEvent = new Truck_Start(startTime);
            pq.add(truckStartEvent);
        }
    }

    /**
     * Creates train events. Reads through given file and parses information containing 
     * time and duration. Creates the train events from this information.
     * 
     * @param filename the given file being read
     * @throws IOException exception thrown if file is not found
     */
    public static void makeTrains(String filename) throws IOException{
        
        String line = null;
        String[] lineList;
    
            // reads file
            FileReader fileRead = new FileReader(filename);
            BufferedReader bufferedRead = new BufferedReader(fileRead);
            line = bufferedRead.readLine();

            // if file line is not empty splits line at space
            while (line != null) {
                lineList = line.split(" ");
                // grabs information from split
                String startTime = lineList[0];
                String duration = lineList[1];

                // type casts strings to doubles
                double time = Double.parseDouble(startTime);
                double dur =  Double.parseDouble(duration);

                System.out.println(startTime + "-" + (time + dur));

                // creates train events using information from file
                Train_Start trainStart = new Train_Start(time);
                pq.add(trainStart);
                Train_End trainEnd = new Train_End((time + dur));
                pq.add(trainEnd);

                // reads next line
                line = bufferedRead.readLine();
            
            }
            bufferedRead.close();
        }

    }
