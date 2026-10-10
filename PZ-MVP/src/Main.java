public final class Main {
    private Main() {
    }

    public static void main(String[] args) {
        TaskModel model = new TaskModel();
        TaskView view = new ConsoleTaskView();
        TaskPresenter presenter = new TaskPresenter(model, view);
        view.setPresenter(presenter);
        view.start();
    }
}
