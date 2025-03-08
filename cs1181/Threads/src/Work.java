import java.util.ArrayList;

public class Work extends Thread {
    //private int threadNum;
    //private static final int JOB_COUNT = 1000;
    static Manager myManager;

    public Work(Manager myManager) {
        //this.threadNum = threadNum;
        Work.myManager = myManager;
    }
    @Override 
    public void run() {
        int nextJob; 
        nextJob = myManager.getNextJob();
        while (nextJob != -1) {
            myManager.doWork(nextJob);
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            myManager.doWork(nextJob);
        }
        // while (myManager.getNextJob() < JOB_COUNT) {
        //     work[nextJob]++;
        //     nextJob++;
        // }
        //for (int i = 200 * threadNum; i <= 200 * threadNum; i++) {
            // System.out.println("Worker Thread " + threadNum + " at: " + i);
            // try {
            //     Thread.sleep(1000);
            // } catch (InterruptedException e) {
            //     e.printStackTrace();
            // }
            //work[i]++;
        //}
    }

    public static void main(String[] args) {

        Manager theManager = new Manager();
        ArrayList<Work> work = new ArrayList<>();
        for (int i = 0; i < 5; i++ ) {
        Work myWork = new Work(theManager);
        work.add(myWork);
        myWork.start();
        }

        for (Work myWork : work) {
            try {
                myWork.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        // start calls thread 
        // run calls method
        // for (int i = 0; i <= 10; i++) {
        //     System.out.println("Main Thread at: " + i);
        //     try {
        //         Thread.sleep(500);
        //     } catch (InterruptedException e) {
        //         e.printStackTrace();
        //     }
        // }
        for (int i =0; i < 1000; i++) {
            System.out.println(theManager.work[i]);
        }
        //     try {
        //         Thread.sleep(50);
        //     } catch (InterruptedException e) {
        //         e.printStackTrace();
        //     }
        // }
    }
}
