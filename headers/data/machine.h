/*!
 * \file machine.h
 * \author Ramzy ZEBRIR
 * \version 0.1
 * \date 01/03/2021
 * \see machine_info.h
 *
 * Contains main information about all of the machine
 */
#ifndef PRIM_MACHINE_H
#define PRIM_MACHINE_H

    #include <stdlib.h> //! to use uint

    /*!
     * \enum MachineStuff_S machine.h "headers/data/machine.h"
     * \typedef MachineStuff
     * \brief id associate to the machine to identify them
     *
     * Contains id associate to the machine.
     *
     */
    typedef enum MachineStuff_S {
        MS_COLLECTOR = 1, //!< collector machine
        MS_CONVEYOR_BELT = 2, //!< conveyor belt
        MS_CROSS = 3, //!< cross
        MS_RECYCLING_CENTER = 4, //!< recycling center
        MS_JUNKYARD = 5, //!< junkyard
    } MachineStuff; //!< Link between a machine and a int to recognize them

    /*!
     * \enum Direction_S machine.h "headers/data/machine.h"
     * \typedef Direction
     * \brief IN if it's the direction of the transit, else out, none if it's not a enter and not a exit
     *
     * Contains id associate to the machine.
     *
     */
    typedef enum Direction_S {
        DIRECTION_IN = 0,
        DIRECTION_OUT = 1,
        DIRECTION_NONE = 2,
    } Direction; //!< Direction

    /*!
     * \typedef Orientation
     * \struct Orientation_S machine.h "headers/data/machine.h"
     *
     * Struct which contains the 4 direction possible for a machine
     *
     */
    typedef struct Orientation_S {
        Direction top; //!< top
        Direction left; //!< left
        Direction bottom; //!< bottom
        Direction right; //!< right
    } Orientation; //!< Orientation

    /*!
     * \typedef Machine
     * \struct Machine_S machine.h "headers/data/machine.h"
     *
     * Struct which contains the main information about a machine
     *
     */
    typedef struct Machine_S {
        MachineStuff type; //!< number associate to the type of the machine
        int level; //!< Represent the level of improvement of the machine
        Orientation orientation; //!< Represent the orientation of the machine
    } Machine; //!< Machine

    /*!
     * \fn MachineStuff machine_getType(Machine* machine)
     * @brief a function to get the type of the machine
     * @param[in] Machine* a machine
     *
     * @return the type of the machine
     */
    MachineStuff machine_getType(Machine* machine);

    /*!
     * \fn int machine_getType(Machine* machine)
     * @brief a function to get the level of the machine
     * @param[in] Machine* a machine
     *
     * @return the level of the machine
     */
    int machine_getLevel(Machine* machine);

    /*!
     * \fn Orientation machine_getOrientation(Machine* machine)
     * @brief a function to get the orientation of the machine
     * @param[in] Machine* a machine
     *
     * @return the orientation of the machine
     */
    Orientation  machine_getOrientation(Machine* machine);

    /*!
     * \fn Direction machine_getOrientationTop(Orientation* orient)
     * @brief a function to get the top orientation of the machine
     * @param[in] Machine* a machine
     *
     * <ul>
     *  <li> DIRECTION_IN = 0
     *  <li> DIRECTION_OUT = 1
     *  <li> DIRECTION_NONE = 2
     * </ul>
     *
     * @return the top orientation of the machine
     */
    Direction  machine_getOrientationTop(Orientation* orient);

    /*!
     * \fn Direction machine_getOrientationBottom(Orientation* orient)
     * @brief a function to get the bottom orientation of the machine
     * @param[in] Machine* a machine
     *
     * <ul>
     *  <li> DIRECTION_IN = 0
     *  <li> DIRECTION_OUT = 1
     *  <li> DIRECTION_NONE = 2
     * </ul>
     *
     * @return the bottom orientation of the machine
     */
    Direction  machine_getOrientationBottom(Orientation* orient);

    /*!
     * \fn Direction machine_getOrientationLeft(Orientation* orient)
     * @brief a function to get the left orientation of the machine
     * @param[in] Machine* a machine
     *
     * <ul>
     *  <li> DIRECTION_IN = 0
     *  <li> DIRECTION_OUT = 1
     *  <li> DIRECTION_NONE = 2
     * </ul>
     *
     * @return the left orientation of the machine
     */
    Direction  machine_getOrientationLeft(Orientation* orient);

    /*!
     * \fn Direction machine_getOrientationRight(Orientation* orient)
     * @brief a function to get the right orientation of the machine
     * @param[in] Machine* a machine
     *
     * <ul>
     *  <li> DIRECTION_IN = 0
     *  <li> DIRECTION_OUT = 1
     *  <li> DIRECTION_NONE = 2
     * </ul>
     *
     * @return the right orientation of the machine
     */
    Direction  machine_getOrientationRight(Orientation* orient);

    /*!
     * \fn Orientation machine_generateDefaultOrientation(MachineStuff s)
     * @brief a function to get a default orientation for a machine
     * @param[in] MachineStuff a type machine
     *
     * This fonction get D:
     * MS_COLLECTOR = 1, collector machine
     * <pre>
     *      None
     *  None x None
     *      Out
     * </pre>
     *
     * MS_CONVEYOR_BELT = 2, conveyor belt
     * <pre>
     *      In
     *   In x In
     *     Out
     * </pre>
     *
     *
     * MS_CROSS = 3, cross
     * <pre>
     *      In
     *  Out x In
     *     Out
     * </pre>
     *
     * MS_RECYCLING_CENTER = 4, recycling center
     * <pre>
     *      In
     *   In x In
     *     Out
     * </pre>
     *
     * MS_JUNKYARD = 5, junkyard
     * <pre>
     *      In
     *   In x In
     *     In
     * </pre>
     * @return a default orientation for a machine
     */
    Orientation machine_generateDefaultOrientation(MachineStuff s);

    // TODO Antoine Faire la doc + signature + implémentation et trouver un autre nom de fonction
    // une méthode un peu complexe (tu peux me redemander après
    // comment cet entier est calculé
    int machine_getOrientationBis(Orientation o);

    /*!
     * \fn Orientation* machine_rotateMachine(Orientation* o, int rotation)
     * @brief a function to rotate the orientation of a machine
     * @param[in] Orientation* an orientation
     * @param[in] int a rotation
     *
     * This function rotate the orientation of a machine in clockwise
     * The int rotation can be a negative value.
     *
     * @return the new orientation after the clockwise rotation
     */
    Orientation* machine_rotateMachine(Orientation* o, int rotation);

#endif //PRIM_MACHINE_H