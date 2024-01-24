package test.grader;

import logic.game.GameManager;
import logic.game.Player;
import logic.rocks.NormalRock;
import logic.zombies.Zombie;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class GameManagerTest {

    @Test
    void testAttackZombie() {
        Player terry = new Player(250);
        GameManager.initializeManager(terry);

        NormalRock rockA = new NormalRock(25);
        NormalRock rockB = new NormalRock(13);

        GameManager.currentRock = rockA;
        GameManager.nextRock = rockB;

        Zombie zombie = new Zombie(200, 10, 2);

        assertEquals(11, GameManager.attackZombie(zombie));
        assertEquals(189, zombie.getHealth());
        assertEquals(rockB, GameManager.currentRock);
    }

}
