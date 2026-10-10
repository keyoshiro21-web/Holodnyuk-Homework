import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public final class ConsoleTaskView implements TaskView {
    private final Scanner scanner = new Scanner(System.in);
    private TaskPresenter presenter;

    @Override
    public void setPresenter(TaskPresenter presenter) {
        this.presenter = presenter;
    }

    @Override
    public void start() {
        if (presenter == null) {
            throw new IllegalStateException("Presenter не налаштований.");
        }

        showMessage("Список завдань. Введіть help, щоб переглянути команди.");
        while (true) {
            System.out.print("> ");
            if (!scanner.hasNextLine()) {
                showMessage("Роботу завершено.");
                return;
            }

            String input = scanner.nextLine().trim();
            if (input.isEmpty()) {
                continue;
            }

            String[] command = input.split("\\s+", 2);
            String argument = command.length == 2 ? command[1].trim() : "";
            switch (command[0].toLowerCase(Locale.ROOT)) {
                case "list":
                    presenter.showTasks();
                    break;
                case "add":
                    if (argument.isEmpty()) {
                        showError("Вкажіть назву: add <назва завдання>");
                    } else {
                        presenter.addTask(argument);
                    }
                    break;
                case "done":
                    runWithId(argument, "done <id>", true);
                    break;
                case "delete":
                    runWithId(argument, "delete <id>", false);
                    break;
                case "help":
                    showHelp();
                    break;
                case "exit":
                    showMessage("Роботу завершено.");
                    return;
                default:
                    showError("Невідома команда. Введіть help, щоб переглянути команди.");
            }
        }
    }

    private void runWithId(String argument, String usage, boolean complete) {
        if (argument.isEmpty()) {
            showError("Використання: " + usage);
            return;
        }

        int id;
        try {
            id = Integer.parseInt(argument);
        } catch (NumberFormatException exception) {
            showError("ID має бути цілим числом.");
            return;
        }

        if (complete) {
            presenter.completeTask(id);
        } else {
            presenter.deleteTask(id);
        }
    }

    @Override
    public void showTasks(List<Task> tasks) {
        if (tasks.isEmpty()) {
            showMessage("Список завдань порожній.");
            return;
        }

        for (Task task : tasks) {
            String status = task.isCompleted() ? "виконано" : "у процесі";
            System.out.printf("#%d [%s] %s%n", task.getId(), status, task.getTitle());
        }
    }

    @Override
    public void showMessage(String message) {
        System.out.println(message);
    }

    @Override
    public void showError(String message) {
        System.out.println("Помилка: " + message);
    }

    private void showHelp() {
        showMessage("Команди:");
        showMessage("  list                 — показати всі завдання");
        showMessage("  add <назва>          — додати завдання");
        showMessage("  done <id>            — позначити завдання виконаним");
        showMessage("  delete <id>          — видалити завдання");
        showMessage("  help                 — показати цю довідку");
        showMessage("  exit                 — завершити роботу");
    }
}
