public final class Task {
    private final int id;
    private final String title;
    private final boolean completed;

    public Task(int id, String title, boolean completed) {
        this.id = id;
        this.title = title;
        this.completed = completed;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public boolean isCompleted() {
        return completed;
    }

    public Task withCompleted(boolean completed) {
        return new Task(id, title, completed);
    }
}
