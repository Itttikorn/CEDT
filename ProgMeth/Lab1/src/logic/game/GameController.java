package logic.game;

import logic.components.*;

import java.util.ArrayList;

public class GameController {
    public static GameController instance = null;
    public ArrayList<Market> markets;
    public ArrayList<Player> players;
    public ArrayList<Monster> monsters;
    public ArrayList<Ore> ores;
    public boolean gameEnd = false;

    public GameController() {
        markets = new ArrayList<Market>();
        markets.add(new Market("Taiyo"));
        markets.get(0).getFoods().add(new Food("Bacon", 10, 5));
        markets.get(0).getFoods().add(new Food("Chicken", 15, 7));
        markets.get(0).getFoods().add(new Food("Beef", 20, 12));
        markets.get(0).getPotions().add(new Potion("Middle Heal", 15, createNewStatus(4, 0, 0, 0)));
        markets.get(0).getPotions().add(new Potion("Middle Attack", 15, createNewStatus(0, 0, 4, 0)));
        players = new ArrayList<Player>();
        players.add(new Player("Akira", createNewStatus(10, 2, 4, 2)));
        players.add(new Player("Ayane", createNewStatus(5, 3, 3, 6), 6, 1200));
        monsters = new ArrayList<Monster>();
        monsters.add(new Monster("Boar", createNewStatus(12, 2, 1, 2)));
        monsters.add(new Monster("Basilisk", createNewStatus(7, 4, 6, 0)));
        monsters.get(0).setFood(new Food("Boar bacon", 20, 7));
        monsters.get(0).setPotion(new Potion("Little Hp Potion", 10, createNewStatus(1, 0, 0, 0)));
        monsters.get(1).setFood(new Food("Basilisk meat", 70, 20));
        monsters.get(1).setPotion(new Potion("Medium Potion", 40, createNewStatus(4, 2, 3, 3)));
        ores = new ArrayList<Ore>();
        ores.add(new Ore("Gold", 180));
        ores.add(new Ore("Silver", 140));
        ores.add(new Ore("Platinum", 250));
        ores.add(new Ore("Bronze", 40));
    }

    public static GameController getInstance() {
        if (instance == null) {
            instance = new GameController();
        }
        return instance;
    }

    public static Status createNewStatus(int hp, int durable, int attack, int magic) {
        if (hp < 0 || durable < 0 || attack < 0 || magic < 0) {
            return null;
        }
        try {
            return new Status(hp, durable, attack, magic);
        } catch (Exception e) {
            //do nothing
        }
        return null;
    }

    public void addMarket(Market market) {
        markets.add(market);
    }

    public void addMonster(Monster monster) {
        monsters.add(monster);
    }

    public void addPlayer(Player player) {
        players.add(player);
    }

    public void endDay() {
        for (Player player : players) {
            int energy = player.getEnergy();
            int hp = player.getStatus().getHp();
            int durability = player.getStatus().getDurability();
            int attack = player.getStatus().getAttack();
            int magic = player.getStatus().getMagic();
            int calculatedEnergy = energy - 3;
            int calculatedHp = hp;
            if (calculatedEnergy < 0) {
                calculatedHp = hp + calculatedEnergy;
                if (calculatedHp < 0) {
                    calculatedHp = 0;
                }
                calculatedEnergy = 0;
            }
            Status newStatus = createNewStatus(calculatedHp, durability, attack, magic);
            player.setEnergy(calculatedEnergy);
            player.setStatus(newStatus);
        }
    }

    public void removeDeadPlayerAndMonster() {
        for (int i = monsters.size() - 1; i >= 0; i--) {
            if (monsters.get(i).getStatus().getHp() <= 0) {
                monsters.remove(i);
            }
        }
        for (int i = players.size() - 1; i >= 0; i--) {
            if (players.get(i).getStatus().getHp() <= 0) {
                players.remove(i);
            }
        }
    }

    public boolean buyOre(int player, int number) {
        return players.get(player).buyOre(ores.get(number));
    }

    public boolean checkGameEnd() {
        if (gameEnd == true) {
            return true;
        }
        for (int i = 0; i < players.size(); ++i) {
            boolean haveFourOres = true;
            for (int j = 0; j < 4; ++j) {
                if (players.get(i).getOres().contains(ores.get(j)) == false) {
                    haveFourOres = false;
                    break;
                }
            }
            if (haveFourOres == true) {
                System.out.println("Player : " + players.get(i).getName() + " Win");
                gameEnd = true;
                return gameEnd;
            }
        }
        return gameEnd;
    }
}
