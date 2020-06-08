// Alec Guilin
// CS 351
// May 10 2019

import java.util.concurrent.Semaphore;

public class guilin 
{
    static Semaphore writer_lock = new Semaphore(1, true); //permits only one thread at a time for writer_lock var
    static Semaphore reader_lock = new Semaphore(1, true); //permits only one thread at a time for reader_lock var
    static int read_count = 0; //number of processes performing read in the critical section

    public class Writer implements Runnable //runnable object is passed to class constructor
    {
        public void run() 
        {
            //error catching for acquire method (throws exception if current thread is interrupted)
            try 
            {
                System.out.println(Thread.currentThread().getName() + " writing");
                writer_lock.acquire(); //acquires permit from semaphore
                
                Thread.sleep((long)(Math.random() * 1000)); //puts current thread in wait state
                
                writer_lock.release(); //releases permit, returning it to the semaphore
                System.out.println(Thread.currentThread().getName() + " finished writing");
            } 

            catch (InterruptedException e) 
            {
                System.out.println("error: current thread is interrupted");
            }
        }
    }

    public class Reader implements Runnable 
    {
        public void run() 
        {
            //error catching for acquire method (throws exception if current thread is interrupted)
            try 
            {
                //reader wants to enter critical section
                System.out.println(Thread.currentThread().getName() + " reading");
                reader_lock.acquire(); //acquire permit
                read_count++; //increment # of readers
               
                //checks if there is a reader in critical section (preference to readers)
                if (read_count == 1)
                    writer_lock.acquire(); //blocks writers

                //additional readers can enter while current reader is in crit section
                reader_lock.release();

                //reading
                Thread.sleep((long)(Math.random() * 1000)); //puts current thread in wait state

                reader_lock.acquire(); //reader wants to leave
                read_count--;//decrement # of readers

                //checks if no reader is left in crit section
                if(read_count == 0)
                    writer_lock.release(); //enables writers (writers can enter)

                reader_lock.release(); //reader leaves
                System.out.println(Thread.currentThread().getName() + " finished reading");
            }

            catch (InterruptedException e) 
            {
                System.out.println("error: current thread is interrupted");
            }
        }
    }

    public static void main(String[] args) throws Exception 
    {
        int num_readers = 4;
        int num_writers = 3;
        int num_threads = num_writers + num_readers;

        Reader read = new Reader();
        Writer write = new Writer();

        Thread readerThreads[] = new Thread[num_threads];
        Thread writerThreads[] = new Thread[num_threads];

        for(int i = 0; i < num_readers; i++)
        {
            readerThreads[i] = new Thread(read);
            readerThreads[i].start();            
        }

        for (int i = 0; i < num_writers; i++) 
        {
            writerThreads[i] = new Thread(write);
            writerThreads[i].start();
        }
    }
}