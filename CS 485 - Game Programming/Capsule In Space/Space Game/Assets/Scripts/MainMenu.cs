using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenu : MonoBehaviour
{
    public string newGameScene, levelSelection;
    public string lvl1, lvl2, lvl3;
    public string back;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void NewGame()
    {
        SceneManager.LoadScene(newGameScene);
    }

    public void QuitGame()
    {
        Application.Quit();
    }

    public void LoadLevel()
    {
        SceneManager.LoadScene(levelSelection);
    }

    public void LoadLevel1()
    {
        SceneManager.LoadScene(lvl1);
    }

    public void LoadLevel2()
    {
        SceneManager.LoadScene(lvl2);
    }

    public void LoadLevel3()
    {
        SceneManager.LoadScene(lvl3);
    }

    public void Return()
    {
        SceneManager.LoadScene(back);
    }
}
