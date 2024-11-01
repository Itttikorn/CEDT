package logic;

import java.util.ArrayList;

public class User {
    private String name;
    private String status;
    private final ArrayList<Server> joinedServersList;

    public User(String name) {
        setName(name);
        status = "hi there, i'm new here";
        joinedServersList = new ArrayList<Server>();
    }

    @Override
    public boolean equals(Object other) {
        if (other == null)
            return false;
        User userToCheck = (User) other;
        return name.equals(userToCheck.getName());
    }

    public void addJoinedServersList(Server s) {
        if (s != null) {
            joinedServersList.add(s);
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name.isBlank()) {
            this.name = "Nobody";
        } else {
            this.name = name;
        }
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        if (status.isBlank()) {
        } else {
            this.status = status;
        }
    }

    public ArrayList<Server> getJoinedServersList() {
        return joinedServersList;
    }


}
