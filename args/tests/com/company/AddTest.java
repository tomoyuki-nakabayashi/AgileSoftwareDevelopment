package com.company;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddTest {

    @Test
    void add() {
        Add obj = new Add();
        assertEquals(2, obj.Add(1, 1));
    }
}