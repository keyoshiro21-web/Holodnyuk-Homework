public final class TaskPresenter {
    private final TaskModel model;
    private final TaskView view;

    public TaskPresenter(TaskModel model, TaskView view) {
        this.model = model;
        this.view = view;
    }

    public void showTasks() {
        view.showTasks(model.getTasks());
    }

    public void addTask(String title) {
        try {
            Task task = model.addTask(title);
            view.showMessage("Завдання #" + task.getId() + " додано.");
        } catch (IllegalArgumentException exception) {
            view.showError(exception.getMessage());
        }
    }

    public void completeTask(int id) {
        if (model.completeTask(id)) {
            view.showMessage("Завдання #" + id + " позначено як виконане.");
        } else {
            view.showError("Завдання #" + id + " не знайдено.");
        }
    }

    public void deleteTask(int id) {
        if (model.deleteTask(id)) {
            view.showMessage("Завдання #" + id + " видалено.");
        } else {
            view.showError("Завдання #" + id + " не знайдено.");
        }
    }
}
