import java.util.List;

public interface TaskView {
    void setPresenter(TaskPresenter presenter);

    void start();

    void showTasks(List<Task> tasks);

    void showMessage(String message);

    void showError(String message);
}
