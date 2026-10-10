import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public final class TaskModel {
    private final List<Task> tasks = new ArrayList<>();
    private int nextId = 1;

    public Task addTask(String title) {
        if (title == null || title.trim().isEmpty()) {
            throw new IllegalArgumentException("Назва завдання не може бути порожньою.");
        }

        Task task = new Task(nextId++, title.trim(), false);
        tasks.add(task);
        return task;
    }

    public List<Task> getTasks() {
        return Collections.unmodifiableList(new ArrayList<>(tasks));
    }

    public boolean completeTask(int id) {
        for (int i = 0; i < tasks.size(); i++) {
            Task task = tasks.get(i);
            if (task.getId() == id) {
                tasks.set(i, task.withCompleted(true));
                return true;
            }
        }
        return false;
    }

    public boolean deleteTask(int id) {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks.get(i).getId() == id) {
                tasks.remove(i);
                return true;
            }
        }
        return false;
    }
}
