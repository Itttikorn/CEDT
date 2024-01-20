package logic;

import java.util.ArrayList;

public class Server {
    private String name;
    private User owner;
    private ArrayList<Channel> channelList;
    private ArrayList<User> memberList;

    public Server(String name, User owner, TemplateType template) {
        setOwner(owner);
        setMemberList(new ArrayList<>());
        setChannelList(new ArrayList<>());
        getMemberList().add(owner);
        owner.getJoinedServersList().add(this);
        setName(name);
        if (template == TemplateType.BASIC) {
            addChannel(owner, "general");
        } else if (template == TemplateType.GAMING) {
            addChannel(owner, "gaming");
        } else if (template == TemplateType.STUDY) {
            addChannel(owner, "homework-help");
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name.isBlank()) {
            name = getOwner().getName() + " home";
        }
        this.name = name;
    }

    public User getOwner() {
        return owner;
    }

    public void setOwner(User owner) {
        this.owner = owner;
    }

    public ArrayList<Channel> getChannelList() {
        return channelList;
    }

    public void setChannelList(ArrayList<Channel> channelList) {
        this.channelList = channelList;
    }

    public ArrayList<User> getMemberList() {
        return memberList;
    }

    public void setMemberList(ArrayList<User> memberList) {
        this.memberList = memberList;
    }

    public Channel addChannel(User user, String channelName) {
        if (user == getOwner()) {
            Channel newChannel = new Channel(channelName);
            getChannelList().add(newChannel);
            return newChannel;
        }
        return null;
    }

    public User addUser(User user) {
        if (getMemberList().contains(user)) return null;
        getMemberList().add(user);
        user.getJoinedServersList().add(this);
        return user;
    }

    public boolean kickUser(User kicker, User kicked) throws Exception {
        if (kicker != getOwner()) throw new Exception();
        if (!getMemberList().contains(kicked) || kicked == getOwner()) return false;
        kicked.getJoinedServersList().remove(this);
        getMemberList().remove(kicked);
        return true;
    }
}
