#include <iostream>
#include <vector>

using namespace std;

struct MemoryBlock {
    int start;
    int size;
    string status;
};

class MemoryManager {
private:
    int total_memory;
    int free_memory;
    vector<MemoryBlock> memory_blocks;

public:
    MemoryManager(int total_memory) : total_memory(total_memory), free_memory(total_memory) {}

    pair<int, int> allocateFirstFit(int process_size) {
        for (int i = 0; i < memory_blocks.size(); ++i) {
            if (memory_blocks[i].status == "free" && memory_blocks[i].size >= process_size) {
                memory_blocks[i].status = "allocated";
                free_memory -= process_size;
                return {i, memory_blocks[i].start};
            }
        }
        return {-1, -1};
    }

    pair<int, int> allocateBestFit(int process_size) {
        int best_fit_index = -1;
        int best_fit_size = INT_MAX;

        for (int i = 0; i < memory_blocks.size(); ++i) {
            if (memory_blocks[i].status == "free" && memory_blocks[i].size >= process_size &&
                memory_blocks[i].size < best_fit_size) {
                best_fit_index = i;
                best_fit_size = memory_blocks[i].size;
            }
        }

        if (best_fit_index != -1) {
            memory_blocks[best_fit_index].status = "allocated";
            free_memory -= process_size;
            return {best_fit_index, memory_blocks[best_fit_index].start};
        }

        return {-1, -1};
    }

    pair<int, int> allocateWorstFit(int process_size) {
        int worst_fit_index = -1;
        int worst_fit_size = 0;

        for (int i = 0; i < memory_blocks.size(); ++i) {
            if (memory_blocks[i].status == "free" && memory_blocks[i].size >= process_size &&
                memory_blocks[i].size > worst_fit_size) {
                worst_fit_index = i;
                worst_fit_size = memory_blocks[i].size;
            }
        }

        if (worst_fit_index != -1) {
            memory_blocks[worst_fit_index].status = "allocated";
            free_memory -= process_size;
            return {worst_fit_index, memory_blocks[worst_fit_index].start};
        }

        return {-1, -1};
    }

    void deallocate(int index) {
        if (index >= 0 && index < memory_blocks.size() && memory_blocks[index].status == "allocated") {
            memory_blocks[index].status = "free";
            free_memory += memory_blocks[index].size;
        }
    }

    void displayMemoryStatus() {
        cout << "Memory Status:" << endl;
        for (int i = 0; i < memory_blocks.size(); ++i) {
            cout << "Block " << i << ": Start=" << memory_blocks[i].start
                 << ", Size=" << memory_blocks[i].size << ", Status=" << memory_blocks[i].status << endl;
        }
        cout << "Free Memory: " << free_memory << endl;
    }
};

int main() {
    int total_memory_size;
    cout << "Enter total memory size: ";
    cin >> total_memory_size;

    MemoryManager memory_manager(total_memory_size);

    // Initial memory blocks
    int num_blocks;
    cout << "Enter the number of memory blocks: ";
    cin >> num_blocks;

    for (int i = 0; i < num_blocks; ++i) {
        MemoryBlock block;
        cout << "Enter start address for Block " << i << ": ";
        cin >> block.start;
        cout << "Enter size for Block " << i << ": ";
        cin >> block.size;
        block.status = "free";
        memory_manager.memory_blocks.push_back(block);
    }

    // Process sizes to allocate
    int num_processes;
    cout << "Enter the number of processes: ";
    cin >> num_processes;

    vector<int> process_sizes(num_processes);
    for (int i = 0; i < num_processes; ++i) {
        cout << "Enter size for Process " << i << ": ";
        cin >> process_sizes[i];
    }

    cout << "\nFirst Fit:" << endl;
    for (int size : process_sizes) {
        auto [index, start] = memory_manager.allocateFirstFit(size);
        if (index != -1) {
            cout << "Allocated " << size << " units at Block " << index << ", Start=" << start << endl;
        } else {
            cout << "Failed to allocate " << size << " units." << endl;
        }
    }

    memory_manager.displayMemoryStatus();

    cout << "\nBest Fit:" << endl;
    memory_manager = MemoryManager(total_memory_size);  // Reset memory manager
    memory_manager.memory_blocks = vector<MemoryBlock>();  // Reset memory blocks

    for (int i = 0; i < num_blocks; ++i) {
        MemoryBlock block;
        cout << "Enter start address for Block " << i << ": ";
        cin >> block.start;
        cout << "Enter size for Block " << i << ": ";
        cin >> block.size;
        block.status = "free";
        memory_manager.memory_blocks.push_back(block);
    }

    for (int size : process_sizes) {
        auto [index, start] = memory_manager.allocateBestFit(size);
        if (index != -1) {
            cout << "Allocated " << size << " units at Block " << index << ", Start=" << start << endl;
        } else {
            cout << "Failed to allocate " << size << " units." << endl;
        }
    }

    memory_manager.displayMemoryStatus();

    cout << "\nWorst Fit:" << endl;
    memory_manager = MemoryManager(total_memory_size);  // Reset memory manager
    memory_manager.memory_blocks = vector<MemoryBlock>();  // Reset memory blocks

    for (int i = 0; i < num_blocks; ++i) {
        MemoryBlock block;
        cout << "Enter start address for Block " << i << ": ";
        cin >> block.start;
        cout << "Enter size for Block " << i << ": ";
        cin >> block.size;
        block.status = "free";
        memory_manager.memory_blocks.push_back(block);
    }

    for (int size : process_sizes) {
        auto [index, start] = memory_manager.allocateWorstFit(size);
        if (index != -1) {
            cout << "Allocated " << size << " units at Block " << index << ", Start=" << start << endl;
        } else {
            cout << "Failed to allocate " << size << " units." << endl;
        }
    }

    memory_manager.displayMemoryStatus();

    return 0;
}
