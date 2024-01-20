package logic;

import java.util.ArrayList;

public class Channel {
    private String name;
    private final ArrayList<Message> messageList;

    public Channel(String name) {
        setName(name);
        messageList = new ArrayList<>();
    }

    public void addMessage(Message message) {
        messageList.add(message);
    }

    public int getMessageCount() {
        return messageList.size();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name.isBlank()) {
            name = "off-topic";
        }
        this.name = name;
    }

    public ArrayList<Message> getMessageList() {
        return messageList;
    }
}
