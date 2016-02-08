#pragma once

#include <string>
#include <map>

using namespace std;

namespace Input
{
	/////////////////////////////////////////////////////////
	/// Class: UserInput
	///
	/// <author>Jeff McCartney</author>
	///
	/// <version>0.1</version>
	///
	/// <summary>
	/// Normalizes user device inputs to actions.
	/// 
	/// What about Progressive inputs or motion control?
	/// Their will be normalized between a value of 0 to 1.
	/// </summary>
	/////////////////////////////////////////////////////////
	class UserInput
	{
	protected:
		map<string, string> m_Actions;
		bool m_Debug;

	public:
		const float KEY_UP = 0.0f;
		const float KEY_DOWN = 1.0f;

		UserInput(void);
		UserInput(string settingsFile);
		~UserInput(void);

		/////////////////////////////////////////////////////////
		/// Function: setDebug
		///
		/// <summary>Prints out debug messages when set to true.
		/// </summary>
		///
		/// <param>debug: Defines wether or not the debug messages
		/// will be printed.</param>
		///
		/// <returns>Returns 0 for a success. Otherwise the
		/// value will be in the error lookup table: <see></see>
		/// </returns>
		/////////////////////////////////////////////////////////
		int setDebug(bool debug);

		/////////////////////////////////////////////////////////
		/// Function: addAction
		///
		/// <summary>Adds an action with an associated input key.
		/// </summary>
		///
		/// <param>actionName: A unique string that respresents the
		/// action.</param>
		///
		/// <param>keyInput: A user periphial input value.</param>
		///
		/// <returns>Returns 0 for a success. Otherwise the
		/// value will be in the error lookup table: <see></see>
		/// </returns>
		/////////////////////////////////////////////////////////
		int addAction(string actionName, string keyInput);

		/////////////////////////////////////////////////////////
		/// Function: getKey
		///
		/// <summary>Gets the associate input key value from the
		/// provided actionName.</summary>
		///
		/// <param>actionName: A unique string representing the 
		/// action.</param>
		///
		/// <returns>Returns the string associated with the
		/// acitonName.
		/// </returns>
		/////////////////////////////////////////////////////////
		string getKey(string actionName);

		/////////////////////////////////////////////////////////
		/// Function: getAction
		///
		/// <summary>Based on the provided keyInput value, this
		/// function will return the associated actionName.</summary>
		///
		/// <param>keyInput: The string repesenting the input key.
		/// </param>
		///
		/// <returns>Returns a string representing the action that
		/// the provided key is associated with.
		/// </returns>
		/////////////////////////////////////////////////////////
		string getAction(string keyInput);

		/////////////////////////////////////////////////////////
		/// Function: setKey
		///
		/// <summary>Changes an existing action to a new key input
		/// value.  If the key input is already associated with 
		/// another action, that action will be set to the unknown
		/// key value.</summary>
		///
		/// <param>actionName: This represents the action to be
		/// changed.  This action must exist.</param>
		///
		/// <param>keyInput: This represents the key input to 
		/// change the action to.</param>
		///
		/// <returns>Returns 0 for a success. Otherwise the
		/// value will be in the error lookup table: <see></see>
		/// </returns>
		/////////////////////////////////////////////////////////
		int setKey(string actionName, string keyInput);

		/////////////////////////////////////////////////////////
		/// Function: setAction
		///
		/// <summary>Sets a given key input to a new action.  This
		/// key input should already exist.  If the given key is
		/// associated with an action, the action will be set to
		/// the unknown key.</summary>
		///
		/// <param>keyInput: The key input to change to the new
		/// action.</param>
		///
		/// <param>actionName: The action to set the keyInput to.
		/// </param>
		///
		/// <returns>Returns 0 for a success. Otherwise the
		/// value will be in the error lookup table: <see></see>
		/// </returns>
		/////////////////////////////////////////////////////////
		int setAction(string keyInput, string actionName);

		/////////////////////////////////////////////////////////
		/// Function: getActionState
		///
		/// <summary>Returns the action state of the given action.
		/// When the key is a simple on/off, the KEY_DOWN/KEY_UP
		/// values will be returned.  When the key is a progressive
		/// key then a float between the value 0 and 1 will be
		/// returned.</summary>
		///
		/// <param>actionName: The action name to get the status of.
		/// </param>
		///
		/// <returns>Returns the action state of the given action.
		/// When the key is a simple on/off, the KEY_DOWN/KEY_UP
		/// values will be returned.  When the key is a progressive
		/// key then a float between the value 0 and 1 will be
		/// returned.
		/// </returns>
		/////////////////////////////////////////////////////////
		float getActionState(string actionName);

		/////////////////////////////////////////////////////////
		/// Function: keyDownListener
		///
		/// <summary>This function is used to track any and all
		/// user inputs and should be used when the user pushes
		/// down a key.</summary>
		///
		/// <param>sender: The object that sent the event.</param>
		///
		/// <param>args: Any arguments that the sender wanted to
		/// send.</param>
		/////////////////////////////////////////////////////////
		void keyDownListener(void* sender, void* args);

		/////////////////////////////////////////////////////////
		/// Function: keyUpListener
		///
		/// <summary>This function is used to track any and all
		/// user inputs and should be used when the user releases
		/// a key.</summary>
		///
		/// <param>sender: The object that sent the event.</param>
		///
		/// <param>args: Any arguments that the sender wanted to
		/// send.</param>
		/////////////////////////////////////////////////////////
		void keyUpListener(void* sender, void* args);
	};
}