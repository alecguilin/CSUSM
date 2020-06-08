package org.psnbtech;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class BoardPanelTest {
	
	private BoardPanel BP;

	@Before
	public void setUp() throws Exception {
		BP = new BoardPanel(null);
	}

	@After
	public void tearDown() throws Exception {
		BP = null;
	}

	
	/* 
	 * checks if position 0,0,0 is empty and valid
	 * then adds a piece and checks to see if 
	 * that position is empty and valid
	*/
	@Test
	public void testIsValidAndEmpty() {
		boolean out;
		
		out = BP.isValidAndEmpty(TileType.TypeI, 0, 0, 0);
		if (out == true) // if position is valid, passed test
			System.out.printf("PASSED");
		else
			fail("NOT PASSED");
		
		BP.addPiece(TileType.TypeI, 0, 0, 0); //adds horizontal piece to board
		out = BP.isValidAndEmpty(TileType.TypeI, 0, 0, 0);
		if (out == false) // position is not valid, passed test
			System.out.printf("PASSED");
		else
			fail("NOT PASSED");
	}

	
	
	/*
	 * 
	 */
	@Test
	public void testAddPiece() {
		boolean out = false;
		BP.addPiece(TileType.TypeI, 0, 0, 0); //adds horizontal piece to board
		
		//scan first 4 blocks horizontally to check if piece is placed correctly
		for (int i = 0; i < 4 && out == false ; i++) {
			out = BP.isValidAndEmpty(TileType.TypeI, i, 0, 0);
		}
		if (out == false) // position is not valid, passed test
			System.out.printf("PASSED");
		else
			fail("NOT PASSED");
		
		
		
		
		
		BP.clear(); //clears board
		BP.addPiece(TileType.TypeI, 0, 0, 1); //adds vertical piece to board
		
		//scan first 4 blocks vertically to check if piece is placed correctly
		for (int i = 0; i < 4 && out == false ; i++) {
			out = BP.isValidAndEmpty(TileType.TypeI, 0, i, 1);
		}
		if (out == false) 
			System.out.printf("PASSED");
		else
			fail("NOT PASSED");
		
		
		
		
	}

	@Test
	public void testCheckLines() {
		for (int i = 0; i < 10; i++)
		{
			BP.addPiece(TileType.TypeI, i, 0, 1);
		}
		System.out.println(BP.checkLines());
		if (BP.checkLines() == 2)
			System.out.printf("PASSED");
		else
			fail("FAIL");
	}

}
