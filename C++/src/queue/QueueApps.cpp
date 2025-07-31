// 1. Task Scheduler simulation
class TaskScheduler {
private:
    struct Task {
        int id;
        int priority;
        int executionTime;
        int arrivalTime;
    };
    priority_queue<Task> taskQueue;
    
public:
    void addTask(int id, int priority, int execTime, int arrivalTime);
    void executeTasks();
    void displayWaitingTasks();
    double getAverageWaitTime();
};

// 2. Call Center simulation
class CallCenter {
private:
    queue<int> incomingCalls;
    queue<int> onHoldCalls;
    int availableAgents;
    
public:
    CallCenter(int agents);
    void receiveCall(int callId);
    void answerCall();
    void endCall();
    void putOnHold(int callId);
    void displayStatus();
};

// 3. Print Queue simulation
class PrintQueue {
private:
    struct PrintJob {
        string document;
        int pages;
        int priority;
        string user;
    };
    queue<PrintJob> printJobs;
    
public:
    void addPrintJob(string doc, int pages, int priority, string user);
    void processPrintJob();
    void cancelJob(string user);
    void displayQueue();
    int estimatedWaitTime();
};

// 4. Web crawler using BFS
class WebCrawler {
private:
    queue<string> urlQueue;
    unordered_set<string> visited;
    
public:
    void addURL(string url);
    void crawl();
    bool isVisited(string url);
    vector<string> extractLinks(string url);
    void displayCrawledData();
};