package Exercise01;

import org.junit.jupiter.api.Test;

import static org.junit.Assert.*;

class StorageBoxTest {

	@Test
	void testIsEmpty() {
		StorageBox a = new StorageBox();
		assertTrue(a.isEmpty());

		a.push(new Object());
		assertFalse(a.isEmpty());

		a.push(new Object());
		assertFalse(a.isEmpty());

		a.pop();
		assertFalse(a.isEmpty());

		a.pop();
		assertTrue(a.isEmpty());

		a.pop();
		assertTrue(a.isEmpty());

	}

	@Test
	void testIsFull() {

	}

	@Test
	void testPush() {
		StorageBox a = new StorageBox();
		Object[] xs = new Object[7];
		for (int i = 0; i < xs.length; i++) {
			xs[i] = new Integer(i);
		}

		for (int i = 0; i < xs.length; i++) {
			a.push(xs[i]);
			assertEquals(xs[i], a.top());
		}

	}

	@Test
	void testPopAndTop() {
		StorageBox a = new StorageBox();
		Object[] xs = new Object[7];
		for (int i = 0; i < xs.length; i++) {
			xs[i] = new Integer(i);
		}
		for (int i = 0; i < xs.length; i++) {
			a.push(xs[i]);
			assertEquals(xs[i], a.top());
		}
		for (int i = xs.length - 1; i >= 0; i--) {
			assertEquals(xs[i], a.top());
			a.pop();
		}
	}

}
