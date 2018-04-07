import java.util.*;
public class Main {
    static class myEntry implements Comparable<myEntry>{
        int time;
        int level;
        public myEntry(int time, int level){
            this.time = time;
            this.level = level;
        }
        public int compareTo(myEntry other){
            if(time < other.time){
                return -1;
            }else if(time > other.time){
                return 1;
            }else {
                return 0;
            }
        }

    }

    public static void getmaxValue(myEntry[] tasks, myEntry[] machines){
        //从小到大排好序了
        int num = 0;
        int value = 0;
        List<myEntry> machineWithTasks = new ArrayList<>();
        int[] isTook = new int[tasks.length];
        for (myEntry machine : machines){
            int index = -1;
            myEntry lastTask = new myEntry(0,0);
            for (int i = 0; i < tasks.length; i++){
                if(isTook[i] == 0 && tasks[i].time <= machine.time && tasks[i].level <=machine.level){
                    if(tasks[i].level > lastTask.level){
                        lastTask.time =  tasks[i].time;
                        lastTask.level =  tasks[i].level;
                        index = i;
                    }
                }
                if(tasks[i].time > machine.time){
                    break;
                }
            }
            machineWithTasks.add(new myEntry(lastTask.time,lastTask.level));
            if(lastTask.time != 0){
                if(index != -1){
                    isTook[index] = 1;    
                }
                num++;
            }
        }
        for (myEntry machineWithTask : machineWithTasks){
            if(machineWithTask.time == 0){
                continue;
            }else {
                value = value + (machineWithTask.time*200+machineWithTask.level*3);
            }
        }
        System.out.println(num+" "+value);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String firstLine = sc.nextLine();
        String[] machineTask = firstLine.split(" ");
        int machineNum = Integer.valueOf(machineTask[0]);
        int taskNum = Integer.valueOf(machineTask[1]);
        myEntry[] machines = new myEntry[machineNum];
        myEntry[] tasks = new myEntry[taskNum];

        for (int i = 0; i < machineNum; i++){
            String str = sc.nextLine();
            String[] tmp = str.split(" ");
            int time = Integer.valueOf(tmp[0]);
            int level = Integer.valueOf(tmp[1]);
            machines[i] = new myEntry(time,level);
        }
        for (int i = 0; i < taskNum; i++){
            String str = sc.nextLine();
            String[] tmp = str.split(" ");
            int time = Integer.valueOf(tmp[0]);
            int level = Integer.valueOf(tmp[1]);
            tasks[i] = new myEntry(time,level);
        }
        Arrays.sort(machines);
        Arrays.sort(tasks);
        getmaxValue(tasks,machines);
    }
}