/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef MOZILLA_A11Y_XULFormControlAccessible_H_
#define MOZILLA_A11Y_XULFormControlAccessible_H_

// NOTE: alphabetically ordered
#include "AccessibleWrap.h"
#include "FormControlAccessible.h"
#include "HyperTextAccessibleWrap.h"
#include "XULSelectControlAccessible.h"

namespace mozilla {
namespace a11y {

/**
 * Used for XUL progressmeter element.
 */
typedef ProgressMeterAccessible<100> XULProgressMeterAccessible;

/**
 * Used for XUL button.
 *
 * @note  Don't inherit from LeafAccessible - it doesn't allow children
 *         and a button can have a dropmarker child.
 */
class XULButtonAccessible : public AccessibleWrap
{
public:
  enum { eAction_Click = 0 };
  XULButtonAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // nsISupports
  NS_DECL_ISUPPORTS_INHERITED

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;

  // ActionAccessible
  virtual uint8_t ActionCount() MOZ_OVERRIDE;
  virtual void ActionNameAt(uint8_t aIndex, nsAString& aName) MOZ_OVERRIDE;
  virtual bool DoAction(uint8_t aIndex) MOZ_OVERRIDE;

  // Widgets
  virtual bool IsWidget() const MOZ_OVERRIDE;
  virtual bool IsActiveWidget() const MOZ_OVERRIDE;
  virtual bool AreItemsOperable() const MOZ_OVERRIDE;
  virtual Accessible* ContainerWidget() const MOZ_OVERRIDE;

  virtual bool IsAcceptableChild(Accessible* aPossibleChild) const MOZ_OVERRIDE;

protected:
  virtual ~XULButtonAccessible();

  // XULButtonAccessible
  bool ContainsMenu() const;
};


/**
 * Used for XUL checkbox element.
 */
class XULCheckboxAccessible : public LeafAccessible
{
public:
  enum { eAction_Click = 0 };
  XULCheckboxAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;

  // ActionAccessible
  virtual uint8_t ActionCount() MOZ_OVERRIDE;
  virtual void ActionNameAt(uint8_t aIndex, nsAString& aName) MOZ_OVERRIDE;
  virtual bool DoAction(uint8_t aIndex) MOZ_OVERRIDE;
};

/**
 * Used for XUL dropmarker element.
 */
class XULDropmarkerAccessible : public LeafAccessible
{
public:
  enum { eAction_Click = 0 };
  XULDropmarkerAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;

  // ActionAccessible
  virtual uint8_t ActionCount() MOZ_OVERRIDE;
  virtual void ActionNameAt(uint8_t aIndex, nsAString& aName) MOZ_OVERRIDE;
  virtual bool DoAction(uint8_t aIndex) MOZ_OVERRIDE;

private:
  bool DropmarkerOpen(bool aToggleOpen) const;
};

/**
 * Used for XUL groupbox element.
 */
class XULGroupboxAccessible MOZ_FINAL : public AccessibleWrap
{
public:
  XULGroupboxAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
  virtual Relation RelationByType(RelationType aType) MOZ_OVERRIDE;

protected:
  // Accessible
  virtual ENameValueFlag NativeName(nsString& aName) MOZ_OVERRIDE;
};

/**
 * Used for XUL radio element (radio button).
 */
class XULRadioButtonAccessible : public RadioButtonAccessible
{

public:
  XULRadioButtonAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual uint64_t NativeState() MOZ_OVERRIDE;
  virtual uint64_t NativeInteractiveState() const MOZ_OVERRIDE;

  // Widgets
  virtual Accessible* ContainerWidget() const MOZ_OVERRIDE;
};

/**
 * Used for XUL radiogroup element.
 */
class XULRadioGroupAccessible : public XULSelectControlAccessible
{
public:
  XULRadioGroupAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeInteractiveState() const MOZ_OVERRIDE;

  // Widgets
  virtual bool IsWidget() const MOZ_OVERRIDE;
  virtual bool IsActiveWidget() const MOZ_OVERRIDE;
  virtual bool AreItemsOperable() const MOZ_OVERRIDE;
};

/**
 * Used for XUL statusbar element.
 */
class XULStatusBarAccessible : public AccessibleWrap
{
public:
  XULStatusBarAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
};

/**
 * Used for XUL toolbarbutton element.
 */
class XULToolbarButtonAccessible : public XULButtonAccessible
{
public:
  XULToolbarButtonAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual void GetPositionAndSizeInternal(int32_t* aPosInSet,
                                          int32_t* aSetSize) MOZ_OVERRIDE;

  // nsXULToolbarButtonAccessible
  static bool IsSeparator(Accessible* aAccessible);
};

/**
 * Used for XUL toolbar element.
 */
class XULToolbarAccessible : public AccessibleWrap
{
public:
  XULToolbarAccessible(nsIContent* aContent, DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;

protected:
  // Accessible
  virtual ENameValueFlag NativeName(nsString& aName) MOZ_OVERRIDE;
};

/**
 * Used for XUL toolbarseparator element.
 */
class XULToolbarSeparatorAccessible : public LeafAccessible
{
public:
  XULToolbarSeparatorAccessible(nsIContent* aContent,
                                DocAccessible* aDoc);

  // Accessible
  virtual mozilla::a11y::role NativeRole() MOZ_OVERRIDE;
  virtual uint64_t NativeState() MOZ_OVERRIDE;
};

} // namespace a11y
} // namespace mozilla

#endif

